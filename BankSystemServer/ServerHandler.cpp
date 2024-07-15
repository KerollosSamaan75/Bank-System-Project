#include "ServerHandler.h" // Include the header file for ServerHandler

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), userID(ID) // Constructor for ServerHandler, setting userID and parent object
{
    setupRequestHandles(); // Call function to set up request handlers
    loginStatus = false; // Initialize login status to false
}

void ServerHandler::setupRequestHandles()
{
    // Initialize request handlers for different commands
    requestHandlerMap["Login"] = new LoginHandler(dataBase);
    requestHandlerMap["Logout"] = new LogoutHandler(dataBase);
    requestHandlerMap["AddAccount"] = new AddClientHandler(dataBase);
    requestHandlerMap["DeleteAccount"] = new DeleteAccountHandler(dataBase);
    requestHandlerMap["GetAccountBalance"] = new GetAccountBalanceHandler(dataBase);
    requestHandlerMap["GetAccountNumber"] = new GetAccountNumberHandler(dataBase);
    requestHandlerMap["GetTransactionHistory"] = new GetTransactionHistoryHandler(dataBase);
    requestHandlerMap["MakeTransaction"] = new MakeTransactionHandler(dataBase);
    requestHandlerMap["MakeTransfer"] = new MakeTransferHandler(dataBase);
    requestHandlerMap["UpdateAccount"] = new UpdateAccountHandler(dataBase);
    requestHandlerMap["GetBankDataBase"] = new GetBankDataBaseHandler(dataBase);
}

void ServerHandler::run()
{
    statusMessage = "User:" + QString::number(userID) + " is running on thread"; // Log thread start
    logger.logMessage(statusMessage); // Log the thread start message
    Socket = new QTcpSocket(); // Create a new QTcpSocket instance
    Socket->setSocketDescriptor(userID); // Set the socket descriptor for the socket
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection); // Connect readyRead signal to onReadyRead slot
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection); // Connect disconnected signal to onDisconnected slot
    dataBase.initializeMainDatabase(); // Initialize main database
    dataBase.initializeTransactionDatabase(); // Initialize transaction database
    exec(); // Start event loop for this thread
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll(); // Read all data from the socket
    logger.logMessage(QString("Server Received encrypted request From User:%1 Request => %2").arg(userID).arg(ByteArr.toHex())); // Log received encrypted request

    // Decrypt the received data
    QByteArray decryptedData = decryptRequest(ByteArr); // Decrypt the received data
    int padLength = decryptedData.at(decryptedData.length() - 1); // Get padding length
    decryptedData = decryptedData.left(decryptedData.length() - padLength); // Remove padding

    statusMessage = QString("Server Received request From User:%1 Request => %2").arg(userID).arg(QString(decryptedData)); // Log decrypted request
    logger.logMessage(statusMessage); // Log decrypted request

    // Extract the frame size and validate it
    int colonIndex = decryptedData.indexOf(':'); // Find colon separating frame size
    if (colonIndex == -1)
    {
        logger.logMessage("Invalid frame: No colon found."); // Log error if no colon found
        return;
    }

    bool ok;
    int frameSize = QString(decryptedData.left(colonIndex)).toInt(&ok); // Get frame size
    if (!ok || frameSize <= 0)
    {
        logger.logMessage("Invalid frame: Invalid frame size."); // Log error if invalid frame size
        return;
    }

    // Extract the JSON part of the frame and validate its size
    QByteArray jsonData = decryptedData.mid(colonIndex + 1); // Extract JSON data
    if (jsonData.size() != frameSize)
    {
        logger.logMessage("Invalid frame: Frame size does not match JSON data size."); // Log error if frame size does not match JSON data size
        return;
    }

    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData); // Parse JSON data
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        logger.logMessage("Invalid frame: Failed to parse JSON."); // Log error if failed to parse JSON
        return;
    }

    QJsonObject jsonObj = jsonDoc.object(); // Get JSON object
    QString requestsizeStr = jsonObj["RequestSize"].toString(); // Get request size from JSON
    int requestSize = requestsizeStr.toInt(&ok); // Convert request size to integer
    if (!ok || requestSize <= 0)
    {
        logger.logMessage(QString::number(requestSize)); // Log invalid request size
        logger.logMessage("Invalid frame: Invalid request size."); // Log error if invalid request size
        return;
    }

    QString requestData = jsonObj["RequestData"].toString(); // Get request data from JSON
    if (requestData.size() != requestSize)
    {
        logger.logMessage("Invalid frame: Request size does not match actual data size."); // Log error if request size does not match data size
        return;
    }

    // Log the valid request
    statusMessage = QString("Server processing request from User:%1 Request => %2").arg(userID).arg(requestData);
    logger.logMessage(statusMessage); // Log processing of request

    // Process the operation with the valid request data
    Operation(requestData); // Call Operation method with request data
}

QByteArray ServerHandler::decryptRequest(const QByteArray &encryptedData)
{
    QByteArray key = "1234567890123456"; // Encryption key
    QByteArray iv = "1234567890123456"; // Initialization vector
    // Decrypt the data
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::CBC, encryptedData, key, iv, QAESEncryption::PKCS7);
    return decryptedData; // Return decrypted data
}

void ServerHandler::onDisconnected()
{
    if (Socket->isOpen()) // Check if socket is open
    {
        if (loginStatus) // Check if user is logged in
        {
            if (dataBase.setUserLoginState(loginUser, "0")) // Set user's login state to false in database(logout)
            {
                statusMessage = "User: " + QString::number(userID) + " logout form bank system"; // Log user logout
                logger.logMessage(statusMessage); // Log user logout
                loginStatus = false; // Update login status
            }
        }
        Socket->close(); // Close socket
        statusMessage = "User:" + QString::number(userID) + " has disconnected"; // Log user disconnection
        logger.logMessage(statusMessage); // Log user disconnection
    }
}

void ServerHandler::Operation(QString Request)
{
    QStringList List = Request.split(":"); // Split request into components
    if (List.isEmpty())
    {
        sendResponse("Invalid request."); // Send response for invalid request
        return;
    }

    QString HandlerKey = List[0]; // Get request handler key

    if (requestHandlerMap.contains(HandlerKey)) // Check if handler key exists in map
    {
        requestHandlerMap[HandlerKey]->execute(List, statusMessage); // Execute request handler
        sendResponse(statusMessage); // Send response based on execution result
    }
    else
    {
        sendResponse("Unknown request."); // Send response for unknown request
    }
}

void ServerHandler::sendResponse(const QString &Message)
{
    if (Socket->isOpen()) // Check if socket is open
    {
        // Create a QJsonObject with the response size and data
        QJsonObject responseObj;
        responseObj["ResponseSize"] = QString::number(Message.size()); // Response size
        responseObj["ResponseData"] = Message; // Response data

        // Check and update login status based on response
        QStringList list = Message.split(":");
        if (list[0] == "Client" || list[0] == "Admin")
        {
            loginStatus = true; // Update login status for valid login attempts
            loginUser = list[1]; // Update Logged-in user's username.
        }

        // Convert the QJsonObject to a QByteArray
        QJsonDocument doc(responseObj); // Create JSON document from response object
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact); // Convert JSON document to compact JSON

        // Get the size of the jsonData
        qint32 jsonSize = jsonData.size(); // Get size of JSON data

        // Convert jsonSize to a string and append a colon
        QByteArray header = QByteArray::number(jsonSize) + ":"; // Create header with JSON size

        // Construct the frame by concatenating header and jsonData
        QByteArray frame = header + jsonData; // Create frame by concatenating header and JSON data
        Socket->write(frame); // Write frame to socket
        QString logMessage = QString("My server Send Response to User:%1 Response => %2").arg(userID).arg(frame); // Log response sent
        logger.logMessage(logMessage); // Log response sent
    }
    else
    {
        QString logMessage = QString("My server Can't Send Response to User:%1 Because The Socket is Closed").arg(userID); // Log error if socket closed
        logger.logMessage(logMessage); // Log error if socket closed
        qDebug() << logMessage; // Output error to qDebug
    }
}

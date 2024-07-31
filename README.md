# Banking System Project

## Overview
This project implements a Banking System using a client-server model. The system is designed to manage user accounts, facilitate transactions, and provide administrative functionalities. It supports two user types: standard users and admin users, each with specific permissions.

## Features
### User Authentication
- **Log In**: Users can log in using their credentials (username and password). The system verifies the credentials and allows access based on user type.
  
![Screenshot_42](https://github.com/user-attachments/assets/98b1c57d-80dc-4664-97a3-b8abcd7a0ada)


### Account Management
- **Get Account Number**: Users can retrieve their account number using their username.
- **View Account Balance**: Both users and admins can view the balance of any account by providing the account number.
- **View Transaction History**: Users and admins can request the last `count` transactions for a specific account, sorted by date.
  
 ![Screenshot_43](https://github.com/user-attachments/assets/c2447c59-93e8-4765-97de-360a2761eac1)
![Screenshot_48](https://github.com/user-attachments/assets/e17c152b-e976-4fd8-8928-479bfa518fdd)


### Transactions
- **Make Transaction**: Users can modify their account balance by making transactions. Positive amounts increase the balance, while negative amounts decrease it.
- **Transfer Amount**: Users can transfer funds between accounts, ensuring that the transfer amount is positive and does not exceed the balance of the sending account.
  
![Screenshot_51](https://github.com/user-attachments/assets/0241bbfb-ea60-418c-834a-d991625f7d45)


### Database Access
- **View Bank Database**: Admins can read the entire bank database, which includes user details and account balances.
- **Create New User**: Admins can create new users by providing user data in a specified format.
- **Delete User**: Admins can delete users from the database using their account number.
- **Update User**: Admins can update user information with optional fields.

### Multi-threading
- The server is capable of handling multiple requests from different clients simultaneously using threads, ensuring efficient processing of requests.

### Encryption
- All client requests are encrypted before being sent to the server. The server decrypts the requests for processing, ensuring data security.

## Technologies Used
- **Framework**: QT/C++ for building the client and server applications.
- **Communication**: Sockets for client-server communication, allowing real-time data exchange.
- **Design Principles**: Object-Oriented Programming (OOP) principles to ensure modular and maintainable code.

## Requirements
1. **Distributed Applications**: The system consists of two separate applications: one for the client and one for the server.
2. **User Types**: The system supports two user types: standard users and admin users, with specific authorization levels.
3. **Client Application**: A GUI application that runs continuously until the user logs out or exits.
4. **Server Application**: A console application that runs in the background, processing requests.
5. **Bonus Features**:
   - Server as a system service (systemctl).
   - Logging of client requests to a file for auditing purposes.
   - Email notifications for client responses.

## Installation
1. **Clone the Repository**:
   ```bash
   git clone (https://github.com/KerollosSamaan75/Bank-System-Project.git)
   ```
2. **Build the Applications**:
   - Open the project in QT Creator.
   - Build both the client and server applications.

## Usage
- **Client**: 
  - Launch the client application.
  - Log in using your username and password.
  - Use the GUI to navigate through account management and transaction functionalities.
  
- **Server**: 
  - Start the server application in a console window.
  - The server will listen for incoming client requests.

## Bonus Features
- **Signature Verification**: Each request can include a signature for added security. The server verifies the signature before processing the request.
- **Email Notifications**: Responses to client requests can be sent to the associated email address of the user.
- **Enhanced Output Formatting**: The client application formats JSON data into human-readable tables for better clarity.

## Diagrams
- Sequence, Class, and State diagrams will be provided in the documentation to illustrate the system architecture and interactions.

## License
This project is licensed under the MIT License.

## Acknowledgments
- [QT Documentation](https://doc.qt.io/)
- [C++ Sockets Programming](https://www.geeksforgeeks.org/socket-programming-cc/)
- Special thanks to contributors and mentors who provided guidance throughout the project.

@echo off
setlocal

:: Get the command line arguments
set "TO=%~1"
set "SUBJECT=%~2"
set "BODY=%~3"

:: Check if the 'TO' email address is valid
if "%TO%"=="" (
    echo No recipient email address provided.
    exit /b 1
)

:: Construct the PowerShell command with correct SMTP server details
powershell -Command "Send-MailMessage -From 'kerosamaan07@gmail.com' -To '%TO%' -Subject '%SUBJECT%' -Body '%BODY%' -SmtpServer 'smtp.gmail.com' -Port 587 -UseSsl -Credential (New-Object PSCredential('kerosamaan07@gmail.com', (ConvertTo-SecureString 'jvra hfos yefp ejcl' -AsPlainText -Force)))"

:: Check for errors in the PowerShell execution
if %ERRORLEVEL% neq 0 (
    echo Error sending email. Check the PowerShell command for details.
    exit /b %ERRORLEVEL%
)

endlocal

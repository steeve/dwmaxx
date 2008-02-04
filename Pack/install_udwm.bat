@echo off

set uDWMFile=uDWM.dll
set uDWMBackupFile=uDWM.backup.dll
set uDWMDestination=%windir%\System32\%uDWMFile%
set uDWMBackupDestination=%windir%\System32\%uDWMBackupFile%
set ACLFile=uDWM.acl

echo This quick installer is going to replace your system %uDWMFile% with our own %uDWMFile%.
echo It will stop the DWM, replace the file and restart it.
echo A backup copy of your file will be located at %uDWMBackupDestination%
echo.
echo Do _NOT_ continue unless you're very sure!
pause

echo Stopping DWM
net stop UxSMS
echo.

echo.
echo Backuping %uDWMFile% to %uDWMBackupFile%
copy "%uDWMDestination%" "%uDWMBackupDestination%"
echo.

echo.
echo Taking ownership of "%uDWMDestination%"
takeown /F "%uDWMDestination%"
echo.

echo Granting full control rights to %uDWMDestination%
icacls "%uDWMDestination%" /grant Administrators:(F)
echo.

echo Overwriting %uDWMDestination% with local %uDWMFile%
copy /Y "%uDWMFile%" "%uDWMDestination%"
echo.

echo Restoring rights and ownership
icacls "%uDWMDestination%" /setowner "NT SERVICE\TrustedInstaller"
icacls "%uDWMDestination%" /grant:r Administrators:(RX)
echo.

echo Patched! Restarting DWM!
net start UxSMS
echo.

echo You are done, you can close this window :)
echo Don't forget the backup file at %uDWMBackupDestination% !
pause


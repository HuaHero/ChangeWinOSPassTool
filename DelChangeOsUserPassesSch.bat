rem @echo off
rem description:ɾ�����ڼƻ�����ִ��ChangeOsUserPasses.exe�������޸�Windows�˻�������

md "%WinDir%\system32\test_permissions" 2>NUL||(echo ��ʹ�ù���Ա��ݵ�¼���У�&&Paulse >NUL&& exit)
rd "%WinDir%\system32\test_permissions" 2>NUL

set curDir=%~dp0
echo %curDir%

schtasks /Delete /TN "ChangeOsUserPassesPlan" /F

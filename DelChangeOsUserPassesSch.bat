rem @echo off
rem description:删除周期计划任务，执行ChangeOsUserPasses.exe，定期修改Windows账户的密码

md "%WinDir%\system32\test_permissions" 2>NUL||(echo 请使用管理员身份登录运行！&&Paulse >NUL&& exit)
rd "%WinDir%\system32\test_permissions" 2>NUL

set curDir=%~dp0
echo %curDir%

schtasks /Delete /TN "ChangeOsUserPassesPlan" /F

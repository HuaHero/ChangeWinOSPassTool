// ChangeOsUserPasses.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CSVReader.h"
#include <fstream>
#include<iostream>

#include"logger.h"

#include "UAC.h"
#include "Windows\winUAC.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	//�����Windows
	winUAC winDows;
	string curFile=__FILE__;
	string curFunc=__FUNCTION__;
	string space="\t";
	string curLog=curFile.append(space).append(curFunc).append(space);
	logger::getInstance()->operator<<( curLog + "begin to change the OS accounts' password");
	(void)winDows.ChangeAccountsPass();
	//system("pause");
	return 0;
}




#include "winUAC.h"
#include <map>
#include<iostream>

//#include<Windows.h>
int winUAC::ChangeAccountsPass()
{
	//map<string,string> accounts_pass_map;
	int i=setAccounts();
	int success=0;
	string curFile=__FILE__;
	string curFunc=__FUNCTION__;
	string space="\t";
	string curLog=curFile.append(space).append(curFunc).append(space),tmp="";  //tmp��ζ��ÿ���õ�����ֱ������ֵ;
	if (0 >= i)
	{
		tmp=curLog+"There is no accounts";
		cout<<tmp<<endl;
		logger::getInstance()->operator<<(tmp);
	}
	else
	{
		vector<string> passes=csvReaderPt->getWordFromNthLine(idx+1);
		if (0 == passes.size())
		{
			tmp=curLog+"there is no passwords stored!";
			cout<<tmp<<endl;
			logger::getInstance()->operator<<(tmp);
			return 0;
		}else
		{
			passes.erase(passes.begin());   //ȥ����һ�еı�ǩ
		}
		if (passes.size() != accounts.size())
		{
			tmp=curLog+"the size of accounts is not equal to the size of passwords";
			cout<<tmp<<endl;
			logger::getInstance()->operator<<(tmp);
			return 0;
		}else
		{
			for (unsigned int k = 0; k < passes.size(); k++)
			{
				string cmd="net user ";
				
				string account=accounts.at(k);
				account.erase(0,account.find_first_not_of(" "));   //ȥ���˻����дӿ�ʼ����һ�����ǿո��м���ַ�����ɾ����ո�
				account.erase(account.find_last_not_of(" ")+1);  //ȥ���˻���������һ�����ǿո��ַ������һ���ַ��м�Ŀո񣬼�ɾ����ո�
				string pass=passes.at(k);
				pass.erase(0,pass.find_first_not_of(" "));   //ȥ�������дӿ�ʼ����һ�����ǿո��м���ַ�����ɾ����ո�
				pass.erase(pass.find_last_not_of(" ")+1);  //ȥ������������һ�����ǿո��ַ������һ���ַ��м�Ŀո񣬼�ɾ����ո�
				cmd.append(" \"").append(account).append("\" ").append("\"").append(pass).append("\"").c_str();
				int res=system(cmd.c_str());
				//ShellExecuteEx();
				if (0 == res)
				{
					tmp="successed to change user:\""+account+"\" 's password";
					cout<<tmp<<endl;
					logger::getInstance()->operator<<(curLog+tmp);
					success++;
				}else    //���ʧ��
				{
					const int WrongSyntax=1,NoUser=2;
					string trans="\"",message="";
					switch (res)
					{
					case WrongSyntax:
						tmp="Wrong Syntax!";
						cout<<tmp;
						message.append(tmp);
						break;
					case NoUser:
						tmp="OS can't find the user:";
						cout<<tmp.append(message.append(trans).append(account).append(trans))<<endl;
						message=tmp;
						break;
					default:
						tmp="the command executed failed!";
						cout<<tmp<< endl;
						break;
					}
					tmp.append(space).append("error:");
					tmp.append(to_string(res));
					logger::getInstance()->operator<<(curLog+tmp);
				}
			}
			if (0 < success) //ֻҪ��һ�������޸ĳɹ��������ֵ���������ʹ����
			{
				(void)idxPlusOne();
			}

		}
	}
	return i;
}

int winUAC::setAccounts()
{
	accounts=csvReaderPt->getWordFromNthLine(0);
	if (0==accounts.size())	//�ļ���������ʱ�������erase���쳣
	{
		return 0;
	}
	accounts.erase(accounts.begin());
	return accounts.size();
}

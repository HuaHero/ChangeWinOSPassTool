
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
	string curLog=curFile.append(space).append(curFunc).append(space),tmp="";  //tmp意味着每次用到可以直接重置值;
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
			passes.erase(passes.begin());   //去掉第一列的标签
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
				account.erase(0,account.find_first_not_of(" "));   //去掉账户名中从开始到第一个不是空格中间的字符，即删除左空格
				account.erase(account.find_last_not_of(" ")+1);  //去掉账户名中最后第一个不是空格字符到最后一个字符中间的空格，即删除左空格
				string pass=passes.at(k);
				pass.erase(0,pass.find_first_not_of(" "));   //去掉密码中从开始到第一个不是空格中间的字符，即删除左空格
				pass.erase(pass.find_last_not_of(" ")+1);  //去掉密码中最后第一个不是空格字符到最后一个字符中间的空格，即删除左空格
				cmd.append(" \"").append(account).append("\" ").append("\"").append(pass).append("\"").c_str();
				int res=system(cmd.c_str());
				//ShellExecuteEx();
				if (0 == res)
				{
					tmp="successed to change user:\""+account+"\" 's password";
					cout<<tmp<<endl;
					logger::getInstance()->operator<<(curLog+tmp);
					success++;
				}else    //如果失败
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
			if (0 < success) //只要有一个密码修改成功，则这轮的密码已算使用了
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
	if (0==accounts.size())	//文件名不存在时，下面的erase会异常
	{
		return 0;
	}
	accounts.erase(accounts.begin());
	return accounts.size();
}

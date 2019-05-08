#pragma once
#include<string>
#include<vector>
#include<map>
#include "CSVReader.h"
#include<fstream>
#include<iostream>

#include "logger.h"


using namespace std;
class UAC
{
public:
	UAC(void){
		csvfile="UserPasses.csv";
		indexFile="index";
		csvReaderPt = new CSVReader(csvfile);
		fstream index(indexFile);
		idx=0;
		if (!index)
		{
			//文件不存在，则创建文件
			//cout<<"can't find the file:"<<indexFile<<endl; 
			index.open(indexFile,ios::out|ios::binary);
			index<<idx;
			index.close();
		}
		index>>idx;

		//get the total line count of passwords 
		//open the CSV file
		ifstream fin(csvfile);
		totalRunTimes=0;
		if (!fin)  //如果文件不存在
		{
			cout<<"can't find the file:"<<csvfile<<endl;
		} else
		{
			string line;
			while (getline(fin,line))
			{
				totalRunTimes++;
			}
		}
	}
	~UAC(void){

	}
	vector<string> accounts;
	CSVReader* csvReaderPt;
	/**
	*function: 调用csvReader根据记录当前为第几个周期（index）读取去读取指定密码文件，然后修改相应账户的密码
	*return:返回修改密码成功的账户数
	*/
	int ChangeAccountsPass();
	/**
	*function: 调用csvReader读取去读取指定密码文件第一行账户列表
	*return:返回读取的账户数
	*/
	int setAccounts();  
	int ChangeTheAccoutPass(string account);

	int idxPlusOne(){
		idx++;
		idx=idx%totalRunTimes;
		ofstream index(indexFile);
		index<<idx;  
		return idx;
	};    //下一轮采用的密码表中的第idx周密码,返回更新后的值
	//map<string,string> accounts_pass_map;
	string csvfile;
	string indexFile;

	int idx;  //idx表示这是第几次运行
	unsigned int totalRunTimes;
};



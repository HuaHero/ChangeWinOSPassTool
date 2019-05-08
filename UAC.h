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
			//�ļ������ڣ��򴴽��ļ�
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
		if (!fin)  //����ļ�������
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
	*function: ����csvReader���ݼ�¼��ǰΪ�ڼ������ڣ�index����ȡȥ��ȡָ�������ļ���Ȼ���޸���Ӧ�˻�������
	*return:�����޸�����ɹ����˻���
	*/
	int ChangeAccountsPass();
	/**
	*function: ����csvReader��ȡȥ��ȡָ�������ļ���һ���˻��б�
	*return:���ض�ȡ���˻���
	*/
	int setAccounts();  
	int ChangeTheAccoutPass(string account);

	int idxPlusOne(){
		idx++;
		idx=idx%totalRunTimes;
		ofstream index(indexFile);
		index<<idx;  
		return idx;
	};    //��һ�ֲ��õ�������еĵ�idx������,���ظ��º��ֵ
	//map<string,string> accounts_pass_map;
	string csvfile;
	string indexFile;

	int idx;  //idx��ʾ���ǵڼ�������
	unsigned int totalRunTimes;
};



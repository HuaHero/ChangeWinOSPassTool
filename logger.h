#pragma once
#include <string>
#include<fstream>
#include<iostream>
using namespace std;

class logger
{
	string logFile;
	ofstream log;
public:
	logger(string file):logFile(file)
	{
		if (file.empty())
		{
			cout << "filename is empty,will exit" <<endl;
			return;
		}
		log.open(logFile,ios::out);
	}
	~logger(void);
	/**
	* @brief logger��ʵ��
	* @note  ��ȡ��־��ʵ��
	* @para 
	*/
	//static logger* getInstance(string filename);
	static logger* getInstance();
	void operator<<(string content); //print the content to log file,end by line
private:
	static logger* instance;
};


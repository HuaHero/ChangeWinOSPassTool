#include "stdafx.h"
#include "CSVReader.h"

#include <iostream>
#include <fstream>
#include<sstream>


CSVReader::CSVReader(void)
{
}


CSVReader::~CSVReader(void)
{
}

/*
* Parses through csv file the ith line and returns the data
* in  vector of words.
*/
vector<string> CSVReader::getWordFromNthLine(int ithLine){
	vector<string> vecRowWords;
	string curFile=__FILE__;
	string curFunc=__FUNCTION__;
	string space="\t";
	string curLog=curFile.append(space).append(curFunc).append(space),tmp="";  //tmp意味着每次用到可以直接重置值;
	
	int i=0;
	if (ithLine < 0)
	{
		tmp="method's parameter is illegal!";
		cout<<tmp<< endl;
		logger::getInstance()->operator<<(curLog+tmp);
	}else
	{
		//open the CSV file
		ifstream fin(fileName);

		if (!fin)  //如果文件不存在
		{
			tmp="can't find the file:"+fileName;
			cout<<"can't find the file:"<<fileName<<endl;
			logger::getInstance()->operator<<(curLog+tmp);
		} else
		{
			string line,word;
			while (getline(fin,line))  //read an entire row
			{
				if (ithLine == i)
				{
					// used for breaking words 
					stringstream s(line);
					while (getline(s,word,',')) 
					{
						// add all the column data  of a row to a vector 
						vecRowWords.push_back(word);
					}
					break;
				}
				i++;
			}
		} //fin exist
	}
	return vecRowWords;
}
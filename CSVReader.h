#pragma once
#include <string>
#include <vector>
#include "logger.h"
using namespace std;
class CSVReader
{
	string fileName;
	string delimeter;
public:
	CSVReader(void);
	~CSVReader(void);

	CSVReader(string filename,string delm=","):fileName(filename),delimeter(delm) {}
	/**
	*function: fetch ithLine data from the CSV file into word by word
	*/
	vector<string> getWordFromNthLine(int ithLine);
};


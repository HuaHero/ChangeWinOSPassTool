#include "stdafx.h"
#include "logger.h"
#include<iostream>
using namespace std;

#include <chrono>
#include <ctime>   

logger* logger::instance=NULL;

logger::~logger(void)
{
	if (log.is_open())
	{
		log.close();
	}
	if (NULL != instance)
	{
		delete instance;
		instance = NULL;
	}
}

logger* logger::getInstance()
{
	if (NULL == instance)
	{
		instance = new logger("ChangeOsUserPasses.log");
	}
	return instance;
}

void logger::operator<<(string content)
{
	log<<"["<<__DATE__<<" "<<__TIME__<<"]"<<content<<endl;
}
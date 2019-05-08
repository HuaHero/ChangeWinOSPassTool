#include "..\UAC.h"


class winUAC:public UAC
{
public:
	winUAC(){
	};
	~winUAC(){
		if (NULL!=csvReaderPt)
		{
			delete csvReaderPt;
			csvReaderPt = NULL;
		}
	};
	/**
	*返回这是第几次运行，表示这次要取第几周的密码
	*/
	int getRunTimes();
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

private:
	
};


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
	*�������ǵڼ������У���ʾ���Ҫȡ�ڼ��ܵ�����
	*/
	int getRunTimes();
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

private:
	
};


#pragma once

//��ȡ��������ҳ�����ݵ�����

#include "../mainframe/DBSTask.h"
#include <string>

class DBSSpiderTask : public DBSTask
{
public:
	DBSSpiderTask(const std::string &strWebUrl);
	void run();

private:
	std::string m_strWebUrl;
};
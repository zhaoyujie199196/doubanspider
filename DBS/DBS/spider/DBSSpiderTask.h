#pragma once

//爬取分析单个页面数据的任务

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
#pragma once

#include "../mainframe/DBSTask.h"
#include <string>

class DBSSpiderTask : public DBSTask
{
public:
	DBSSpiderTask(int nTaskKey, const std::string &strUrl);
	~DBSSpiderTask();
	std::shared_ptr<IDBSResult> run();

protected:
	std::string m_strUrl;
};
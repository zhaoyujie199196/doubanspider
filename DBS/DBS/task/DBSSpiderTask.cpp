#include "DBSSpiderTask.h"

DBSSpiderTask::DBSSpiderTask(int nTaskKey, const std::string &strUrl)
	: DBSTask(nTaskKey)
	, m_strUrl(strUrl)
{

}

DBSSpiderTask::~DBSSpiderTask()
{

}

std::shared_ptr<IDBSResult> DBSSpiderTask::run()
{
	return nullptr;
}
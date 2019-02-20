#include "DBSTask.h"
#include "IDBSTask.h"
#include "IDBSResult.h"

DBSTask::DBSTask(int nTaskKey)
	: m_nTaskKey(nTaskKey)
{

}

DBSTask::~DBSTask()
{

}

std::shared_ptr<IDBSResult> DBSTask::run()
{
	return nullptr;
}

int DBSTask::getTaskKey()
{
	return m_nTaskKey;
}


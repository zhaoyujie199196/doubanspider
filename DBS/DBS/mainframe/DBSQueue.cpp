#include "DBSQueue.h"
#include "IDBSTask.h"

DBSQueue::DBSQueue()
{

}

DBSQueue::~DBSQueue()
{

}

std::shared_ptr<IDBSTask> DBSQueue::takeTask()
{
	return std::shared_ptr<IDBSTask>(nullptr);
}

void DBSQueue::appendTask(std::shared_ptr<IDBSTask> pTask)
{
	return;
}
		
	

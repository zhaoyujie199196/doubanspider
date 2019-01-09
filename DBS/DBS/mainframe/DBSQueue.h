#pragma once

#include <memory>

class IDBSTask;
class DBSQueue
{
public:
	DBSQueue();
	~DBSQueue();
	std::shared_ptr<IDBSTask> takeTask();
	void appendTask(std::shared_ptr<IDBSTask> pTask);
};
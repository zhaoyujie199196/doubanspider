#pragma once

//任务线程池

#include <vector>
#include <thread>
#include <memory>

class IDBSTask;
class DBSQueue;
class DBSThreadPool
{
public:
	DBSThreadPool();
	~DBSThreadPool();
	void init();
	void appendTask(std::shared_ptr<IDBSTask> pTask);

protected:
	void execute();

protected:
	std::shared_ptr<DBSQueue> m_pTaskQueue;
	std::vector<std::thread *> m_threadVec;
};
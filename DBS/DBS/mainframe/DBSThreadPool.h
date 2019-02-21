#pragma once

//任务线程池

#include <vector>
#include <thread>
#include <memory>
#include "DBSTaskQueue.h"

class IDBSTask;
class IDBSResultDealer;
class DBSThreadPool
{
public:
	DBSThreadPool();
	~DBSThreadPool();
	void init(int nThreadCount, int nMaxTaskCount, std::shared_ptr<IDBSResultDealer> pDealer);
	void appendTask(std::shared_ptr<IDBSTask> pTask);
	void stop();

protected:
	void execute();

protected:
	volatile bool m_bQuit = false;
	std::shared_ptr<DBSTaskQueue> m_pTaskQueue;
	std::shared_ptr<IDBSResultDealer> m_pResultDealer;
	std::vector<std::shared_ptr<std::thread>> m_threadVec;
};
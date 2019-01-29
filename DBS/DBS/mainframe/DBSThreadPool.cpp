#include "DBSThreadPool.h"
#include "IDBSTask.h"
#include "DBSTaskQueue.h"

DBSThreadPool::DBSThreadPool()
{

}

DBSThreadPool::~DBSThreadPool()
{
	stop();
	for (auto &pThread : m_threadVec)
	{
		pThread->join();
	}
	m_threadVec.clear();
}

void DBSThreadPool::init(int nThreadCount, int nMaxTaskCount)
{
	m_pTaskQueue = std::shared_ptr<DBSTaskQueue>(new DBSTaskQueue(nMaxTaskCount));
	for (int i = 0; i < nThreadCount; ++i)
	{
		std::shared_ptr<std::thread> pThread(new std::thread(&DBSThreadPool::execute, this));
		m_threadVec.emplace_back(pThread);
	}
}

void DBSThreadPool::appendTask(std::shared_ptr<IDBSTask> pTask)
{
	m_pTaskQueue->appendTask(pTask);
}

void DBSThreadPool::stop()
{
	m_bQuit = true;
	m_pTaskQueue->close();
}

void DBSThreadPool::execute()
{
	while (true)
	{
		if (m_bQuit)
			break;
		std::shared_ptr<IDBSTask> pTask = m_pTaskQueue->takeTask();
		if (!pTask)
			break;
		pTask->run();
	}
}

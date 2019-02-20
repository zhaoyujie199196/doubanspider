#include "DBSThreadPool.h"
#include "IDBSTask.h"
#include "DBSTaskQueue.h"
#include "DBSResultDealer.h"

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

void DBSThreadPool::init(int nThreadCount, int nMaxTaskCount, std::shared_ptr<IDBSResultDealer> pDealer)
{
	m_pResultDealer = pDealer;
	m_pTaskQueue = std::shared_ptr<DBSTaskQueue>(new DBSTaskQueue(nMaxTaskCount));
	for (int i = 0; i < nThreadCount; ++i)
	{
		std::shared_ptr<std::thread> pThread(new std::thread(&DBSThreadPool::execute, this));
		m_threadVec.emplace_back(pThread);
	}
}

void DBSThreadPool::appendTask(std::shared_ptr<IDBSTask> pTask)
{
	m_pTaskQueue->appendOne(pTask);
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
		std::shared_ptr<IDBSTask> pTask = m_pTaskQueue->takeOne();
		if (!pTask)
			break;
		std::shared_ptr<IDBSResult> pResult = pTask->run();
		if (m_pResultDealer)
		    m_pResultDealer->deal(pTask->getTaskKey(), pResult);
	}
}

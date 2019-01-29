#pragma once

#include <list>
#include <memory>
#include <mutex>
#include <condition_variable>

class IDBSTask;
class DBSTaskQueue
{
public:
	DBSTaskQueue(int nMaxCount);
	~DBSTaskQueue();
	std::shared_ptr<IDBSTask> takeTask();
	void appendTask(std::shared_ptr<IDBSTask> pTask);
	void close();

protected:
	bool notEmpty();
	bool notFull();

protected:
	int m_nMaxCount = 0;
	volatile bool m_bQuit = false;
	std::list<std::shared_ptr<IDBSTask>> m_TaskList;
	std::mutex m_mutex;
	std::condition_variable m_NotFullCondition;
	std::condition_variable m_NotEmptyCondition;
};
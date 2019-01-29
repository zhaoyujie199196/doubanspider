#include "DBSTaskQueue.h"
#include "IDBSTask.h"
#include "assert.h"

DBSTaskQueue::DBSTaskQueue(int nMaxCount)
{
	assert(nMaxCount > 0);
	m_nMaxCount = nMaxCount;
}

DBSTaskQueue::~DBSTaskQueue()
{

}

std::shared_ptr<IDBSTask> DBSTaskQueue::takeTask()
{
	std::unique_lock<std::mutex> locker(m_mutex);
	m_NotEmptyCondition.wait(locker, [this] {
		return notEmpty() || m_bQuit; 
	});
	if (m_bQuit)
		return nullptr;
	std::shared_ptr<IDBSTask> pTask = *m_TaskList.begin();
	m_TaskList.erase(m_TaskList.begin());
	return pTask;
}

void DBSTaskQueue::appendTask(std::shared_ptr<IDBSTask> pTask)
{
	std::unique_lock<std::mutex> locker(m_mutex);
	m_NotFullCondition.wait(locker, [this] {
		return notFull() || m_bQuit; 
	});
	if (m_bQuit)
		return;
	m_TaskList.emplace_back(pTask);
	m_NotEmptyCondition.notify_one();
	return;
}

void DBSTaskQueue::close()
{
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_TaskList.clear();
		m_bQuit = true;
	}
	m_NotEmptyCondition.notify_all();
	m_NotFullCondition.notify_all();
}

bool DBSTaskQueue::notEmpty()
{
	return !m_TaskList.empty();
}

bool DBSTaskQueue::notFull()
{
	return m_TaskList.size() != m_nMaxCount;
}
		
	

#pragma once

#pragma once

#include <list>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "assert.h"

template <class T>
class DBSQueue
{
public:
	DBSQueue(int nMaxCount)
	{
		assert(nMaxCount > 0);
		m_nMaxCount = nMaxCount;
	}
	~DBSQueue() {}

	T takeOne()
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_NotEmptyCondition.wait(locker, [this] {
			return notEmpty() || m_bQuit;
		});
		if (m_bQuit)
			return nullptr;
		T pData = *m_DataList.begin();
		m_DataList.erase(m_DataList.begin());
		return pData;
	}
	void appendOne(T pTask)
	{
		std::unique_lock<std::mutex> locker(m_mutex);
		m_NotFullCondition.wait(locker, [this] {
			return notFull() || m_bQuit;
		});
		if (m_bQuit)
			return;
		m_DataList.emplace_back(pTask);
		m_NotEmptyCondition.notify_one();
		return;
	}

	void close()
	{
		{
			std::unique_lock<std::mutex> locker(m_mutex);
			m_DataList.clear();
			m_bQuit = true;
		}
		m_NotEmptyCondition.notify_all();
		m_NotFullCondition.notify_all();
	}

protected:
	bool notEmpty()
	{
		return !m_DataList.empty();
	}

	bool notFull()
	{
		return m_DataList.size() != m_nMaxCount;
	}

protected:
	int m_nMaxCount = 0;
	volatile bool m_bQuit = false;
	std::list<T> m_DataList;
	std::mutex m_mutex;
	std::condition_variable m_NotFullCondition;
	std::condition_variable m_NotEmptyCondition;
};
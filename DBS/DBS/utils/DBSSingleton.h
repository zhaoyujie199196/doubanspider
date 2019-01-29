#pragma once

//单例工具类

#include <thread>
#include <mutex>

template <class T>
class DBSSingleton
{
public:
	template <class... ARGS>
	static T *instance(ARGS&&... args) {
		static std::once_flag m_onceFlag;
		if (!m_pInstance) {
			std::call_once(m_onceFlag, [&]{
				m_pInstance = new T(std::forward<ARGS>(args)...); 
			});
		}
		return m_pInstance;
	}

	static void freeInstance() {
		delete m_pInstance;
		m_pInstance = nullptr;
	}

private:
	static T *m_pInstance;
};

template<class T>
T *DBSSingleton<T>::m_pInstance = nullptr;

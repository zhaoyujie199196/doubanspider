#pragma once

//≈¿≥Êπ‹¿Ì¿‡
#include <memory>
#include "core/DBSQueue.h"

class IDBSModel;
class DBSThreadPool;
class IDBSResultDealer;
class IDBSResult;
class DBSTaskData;
class DBSManager
{
public:
	DBSManager();
	~DBSManager();
	void init();
	void exec();
	void exit();

protected:
	void saveUnFinishedTask();
	void putStartUrls();
	void putUnFinishedUrls();
	void onTaskExecOver(std::shared_ptr<IDBSResult> pResult);

protected:
	std::shared_ptr<IDBSModel> m_pModel;
	std::shared_ptr<DBSThreadPool> m_pThreadPool;
	std::shared_ptr<IDBSResultDealer> m_pResultDealer;
	std::shared_ptr<DBSQueue<std::shared_ptr<DBSTaskData>>> m_pPrepareQueue;
	bool m_bIsRunning = true;
};
#pragma once

//≈¿≥Êπ‹¿Ì¿‡
#include <memory>

class IDBSModel;
class DBSThreadPool;
class DBSManager
{
public:
	DBSManager();
	~DBSManager();
	void init();
	void exec();
	void exit();

protected:
	void saveUnFinishTask();
	void putStartUrls();
	bool continueTask();
	bool startWithOri();

protected:
	std::shared_ptr<IDBSModel> m_pModel;
	std::shared_ptr<DBSThreadPool> m_pThreadPool;
	bool m_bIsRunning = true;
};
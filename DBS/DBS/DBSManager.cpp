#include "DBSManager.h"
#include "mainframe/DBSThreadPool.h"
#include "mainframe/DBSTask.h"
#include "model/DBSModel.h"
#include "config/DBSOriUrls.h"

static const int c_nThreadCount = 4;
static const int c_nTaskCacheCount = 20;

DBSManager::DBSManager()
{

}

DBSManager::~DBSManager()
{

}

void DBSManager::init()
{
	m_pModel = std::shared_ptr<DBSModel>(new DBSModel);
	m_pModel->init();
	m_pThreadPool = std::shared_ptr<DBSThreadPool>(new DBSThreadPool);
	m_pThreadPool->init(c_nThreadCount, c_nTaskCacheCount);
}

void DBSManager::exec()
{
	while (m_bIsRunning)
	{

	}
}

void DBSManager::exit()
{
	m_bIsRunning = false;
}

void DBSManager::saveUnFinishTask()
{

}

bool DBSManager::continueTask()
{
	return false;
}

bool DBSManager::startWithOri()
{
	std::shared_ptr<IDBSOriUrls> pOriUrls = std::shared_ptr<IDBSOriUrls>(new DBSOriUrls);
	std::vector<std::string> oriUrls = pOriUrls->getOriUrls();
	for (auto &strUrl : oriUrls)
	{

	}
	return true;
}

void DBSManager::putStartUrls()
{

}
#include "DBSManager.h"
#include "mainframe/DBSThreadPool.h"
#include "mainframe/DBSResultDealer.h"
#include "mainframe/DBSTask.h"
#include "model/DBSModel.h"
#include "config/DBSOriUrls.h"
#include "task/DBSTaskData.h"
#include "task/DBSSpiderTask.h"
#include "DBSDefines.h"

static const int c_nThreadCount = 4;
static const int c_nTaskCacheCount = 5;
static const int c_nPrepareCount = 5;

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
	m_pResultDealer = std::shared_ptr<IDBSResultDealer>(new DBSResultDealer);
	m_pResultDealer->registDealFunc(dbs::c_nTaskId, 
		std::bind(&DBSManager::onTaskExecOver, this, std::placeholders::_1));
	m_pThreadPool = std::shared_ptr<DBSThreadPool>(new DBSThreadPool);
	m_pThreadPool->init(c_nThreadCount, c_nTaskCacheCount, m_pResultDealer);
	m_pPrepareQueue = std::shared_ptr<DBSQueue<std::shared_ptr<DBSTaskData>>>(new DBSQueue<std::shared_ptr<DBSTaskData>>(c_nPrepareCount));
}

void DBSManager::exec()
{
	bool bIsFirst = true;  //TODO
	if (bIsFirst)
		putStartUrls();
	else
		putUnFinishedUrls();

	while (m_bIsRunning)
	{
		std::shared_ptr<DBSTaskData> pData = m_pPrepareQueue->takeOne();
		if (!pData)
			break;
		std::shared_ptr<DBSTask> pTask(new DBSSpiderTask(dbs::c_nTaskId, pData->m_strUrl));
		m_pThreadPool->appendTask(pTask);
	}
}

void DBSManager::exit()
{
	m_bIsRunning = false;
}

void DBSManager::saveUnFinishedTask()
{

}

void DBSManager::putUnFinishedUrls()
{

}


void DBSManager::putStartUrls()
{
	std::shared_ptr<IDBSOriUrls> pOriUrls = std::shared_ptr<IDBSOriUrls>(new DBSOriUrls);
	std::vector<std::string> oriUrls = pOriUrls->getOriUrls();
	for (auto &strUrl : oriUrls)
	{
		std::shared_ptr<DBSTaskData> pData(new DBSTaskData);
		pData->m_strUrl = strUrl;
		m_pPrepareQueue->appendOne(pData);
	}
}

void DBSManager::onTaskExecOver(std::shared_ptr<IDBSResult> pResult)
{

}
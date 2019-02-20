#include "DBSResultDealer.h"
#include "utils/DBSLogTool.h"

DBSResultDealer::DBSResultDealer()
	: IDBSResultDealer()
{

}

DBSResultDealer::~DBSResultDealer()
{
	m_FuncMap.clear();
}

void DBSResultDealer::registDealFunc(int nKey, DBSResultDealFunc pFunc)
{
	m_FuncMap.insert(std::map<int, DBSResultDealFunc>::value_type(nKey, pFunc));
}

void DBSResultDealer::deal(int nKey, std::shared_ptr<IDBSResult> pData)
{
	auto it = m_FuncMap.find(nKey);
	if (it == m_FuncMap.end())
	{
		std::string strLog = "the dealer of key " + std::to_string(nKey) + " has not registed!";
		LOG(strLog);
	}
	else
	{
		it->second(pData);
	}
}


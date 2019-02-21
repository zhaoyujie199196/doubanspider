#pragma once

#include "IDBSResultDealer.h"
#include <map>

class DBSResultDealer : public IDBSResultDealer
{
public:
	DBSResultDealer();
	~DBSResultDealer();
	void registDealFunc(int nKey, DBSResultDealFunc pFunc);
	void deal(int nKey, std::shared_ptr<IDBSResult> pData);

protected:
	std::map<int, DBSResultDealFunc> m_FuncMap;
};
#pragma once

#pragma once

#include <functional>
#include <memory>
#include "IDBSResult.h"

typedef std::function<void(std::shared_ptr<IDBSResult>)> DBSResultDealFunc;

class IDBSResultDealer
{
public:
	IDBSResultDealer() {}
	virtual ~IDBSResultDealer() {}
	virtual void registDealFunc(int nKey, DBSResultDealFunc pFunc) = 0;
	virtual void deal(int nKey, std::shared_ptr<IDBSResult> pData) = 0;
};

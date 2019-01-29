#pragma once

#include "IDBSModel.h"
#include <memory>

class IDBSContainer;
class DBSModel : public IDBSModel
{
public:
	DBSModel();
	~DBSModel();
	void init();
	
protected:
	std::shared_ptr<IDBSContainer> m_pVisitedContainer;   //已经爬过的数据容器
	std::shared_ptr<IDBSContainer> m_pValidContainer;     //有效的数据容器
};
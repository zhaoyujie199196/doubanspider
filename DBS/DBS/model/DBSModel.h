#pragma once

#include "IDBSModel.h"
#include <memory>

class IDBSContainer;
class DBSModel : public IDBSModel
{
public:
	DBSModel();
	~DBSModel();
	
protected:
	std::shared_ptr<IDBSContainer> m_pVisitedContainer;   //�Ѿ���������������
	std::shared_ptr<IDBSContainer> m_pValidContainer;     //��Ч����������
};
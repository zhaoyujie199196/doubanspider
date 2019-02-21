#pragma once

#include "IDBSTask.h"

class IDBSResult;
class DBSTask : public IDBSTask
{
public:
	DBSTask(int nTaskKey);
	~DBSTask();
	std::shared_ptr<IDBSResult> run();
	int getTaskKey();

protected:
	int m_nTaskKey = 0;
};

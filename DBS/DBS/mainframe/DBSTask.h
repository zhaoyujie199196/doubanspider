#pragma once

#include "IDBSTask.h"

class IDBSTaskData;
class DBSTask : public IDBSTask
{
public:
	DBSTask();
	~DBSTask();
	void run();
};

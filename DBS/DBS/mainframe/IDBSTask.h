#pragma once

#include <memory>

class IDBSTaskData;
class IDBSTask
{
public:
	IDBSTask() {}
	virtual ~IDBSTask() {}
	virtual void run() = 0;
};
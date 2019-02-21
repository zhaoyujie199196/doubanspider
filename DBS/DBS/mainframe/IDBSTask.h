#pragma once

#include <memory>

class IDBSResult;
class IDBSTask
{
public:
	IDBSTask() {}
	virtual ~IDBSTask() {}
	virtual std::shared_ptr<IDBSResult> run() = 0;
	virtual int getTaskKey() = 0;

protected:
	
};
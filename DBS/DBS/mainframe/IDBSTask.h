#pragma once

class IDBSTask
{
public:
	IDBSTask() {}
	virtual ~IDBSTask() {}
	virtual void run() = 0;
};
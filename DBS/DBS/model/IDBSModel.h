#pragma once

//模型接口类

class IDBSModel
{
public:
	IDBSModel() {}
	virtual ~IDBSModel() {}
	virtual void init() = 0;
};
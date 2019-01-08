#pragma once

//数据容器，一个容器存放一种特定的数据

#include <memory>

class IDBSItem;
class IDBSContainer
{
public:
	IDBSContainer() {}
	virtual ~IDBSContainer() {}
	//根据键值查找数据
	virtual std::shared_ptr<IDBSItem> getItem(const std::string &strKey) = 0;
	//添加数据
	virtual addItem(std::shared_ptr<IDBSItem> pItem) = 0;
};
#pragma once

#include <vector>

class IDBSOriUrls
{
public:
	IDBSOriUrls() {}
	virtual ~IDBSOriUrls() {}
	virtual std::vector<std::string> getOriUrls() = 0;
};
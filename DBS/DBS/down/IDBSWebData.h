#pragma once

//±£´æÍøÒ³Êý¾Ý

#include <string>

class IDBSWebData
{
public:
	IDBSWebData() {}
	virtual ~IDBSWebData() {}
	virtual std::string getWebSiteKey() = 0;
	virtual std::string getWebContent() = 0;
};
#pragma once

//ÍøÒ³·ÖÎöÆ÷
#include <memory>

class IDBSParseData;
class IDBSWebData;
class IDBSParser
{
public:
	IDBSParser() {}
	virtual ~IDBSParser() {}
	virtual std::shared_ptr<IDBSParseData> doParse(std::shared_ptr<IDBSWebData> pWebData) = 0;
};
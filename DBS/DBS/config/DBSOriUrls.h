#pragma once

#include "IDBSOriUrls.h"

class DBSOriUrls : public IDBSOriUrls
{
public:
	DBSOriUrls();
	~DBSOriUrls();

	std::vector<std::string> getOriUrls();
};
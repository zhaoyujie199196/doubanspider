#pragma once

#include "utils/DBSSingleton.h"
class DBSConfig
{
	friend class DBSSingleton<DBSConfig>;
public:
	static DBSConfig *instance() { return DBSSingleton<DBSConfig>::instance(); }
	static void freeInstance() { return DBSSingleton<DBSConfig>::freeInstance(); }

	const std::string c_strOriUrl = "https://book.douban.com/";	

protected:
	DBSConfig() {}
	~DBSConfig() {}
	DBSConfig(const DBSConfig &config) = delete;
	DBSConfig& operator=(DBSConfig &) = delete;

};
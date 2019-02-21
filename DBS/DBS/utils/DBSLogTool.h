#pragma once

//日志记录类

#include "DBSSingleton.h"
#include <string>
#include <stdio.h>
#include <mutex>

class DBSLogTool
{
	friend class DBSSingleton<DBSLogTool>;

public:
	static DBSLogTool *instance();
	static void freeInstance();
	void log(const std::string &strFile, long nLineNo, const std::string &strFunc, const std::string &strLog);

protected:
	DBSLogTool();
	~DBSLogTool();

private:
	std::mutex m_mutex;
};

#define LOG(strLog) DBSLogTool::instance()->log(__FILE__, __LINE__, __FUNCTION__ , strLog)
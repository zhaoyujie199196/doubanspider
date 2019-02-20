#include "DBSLogTool.h"
#include <iostream>

DBSLogTool *DBSLogTool::instance()
{
	return DBSSingleton<DBSLogTool>::instance();
}

void DBSLogTool::freeInstance()
{
	return DBSSingleton<DBSLogTool>::freeInstance();
}

DBSLogTool::DBSLogTool()
{

}

DBSLogTool::~DBSLogTool()
{

}

void DBSLogTool::log(const std::string &strFile, long nLineNo, const std::string &strFunc, const std::string &strLog)
{
	std::lock_guard<std::mutex> locker(m_mutex);
	std::cout << strFile << "  lineNo:" << nLineNo << "  funcName:" << strFunc << std::endl;
	std::cout << __DATE__<<"  "<<__TIME__<<"  "<<strLog << std::endl;
}
#pragma once

#include "IDBSWebData.h"

class DBSWebData : public IDBSWebData
{
public:
	DBSWebData(const std::string &strWebSite, const std::string &strWebContent);
	~DBSWebData();
	std::string getWebSiteKey();
	std::string getWebContent();

protected:
	std::string m_strWebSite = "";
	std::string m_strWebContent = "";
};
#include "DBSWebData.h"

DBSWebData::DBSWebData(const std::string &strWebSite, const std::string &strWebContent)
	: IDBSWebData()
	, m_strWebSite(strWebSite)
	, m_strWebContent(strWebContent)
{

}

DBSWebData::~DBSWebData()
{

}

std::string DBSWebData::getWebSiteKey()
{
	return m_strWebSite;
}

std::string DBSWebData::getWebContent()
{
	return m_strWebContent;
}
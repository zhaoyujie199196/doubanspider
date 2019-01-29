#include "DBSOriUrls.h"
#include "config/DBSConfig.h"

DBSOriUrls::DBSOriUrls()
{

}

DBSOriUrls::~DBSOriUrls()
{

}

std::vector<std::string> DBSOriUrls::getOriUrls()
{
	std::vector <std::string> result;
	std::string strOriUrl = DBSConfig::instance()->c_strOriUrl;
	result.push_back(strOriUrl);
	return result;
}
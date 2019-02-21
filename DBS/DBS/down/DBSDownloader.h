#pragma once

#include "IDBSDownloader.h"

class DBSDownloader : public IDBSDownloader
{
public:
	DBSDownloader();
	~DBSDownloader();
	EnDownCode download(const std::string &strWebSite, std::string &webContent);
};
#pragma once

#include <string>

//�������ӿ�
class IDBSDownloader
{
public:
	enum EnDownCode {
		DOWN_NO_ERROR
	};

	IDBSDownloader() {}
	virtual ~IDBSDownloader() {}
	virtual EnDownCode download(const std::string &strWebSite, std::string &webContent) = 0;
};
#pragma once

//�������ӿ�
class IDBSDownloader
{
public:
	enum EnDownCode {
		NO_ERROR
	};

	IDBSDownloader() {}
	virtual ~IDBSDownloader() {}
	virtual EnDownCode download(const std::string &strWebSite, std::string &webContent) = 0;
};
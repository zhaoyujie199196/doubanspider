#pragma once

//������ҳ����

class IDBSWebData
{
public:
	IDBSWebData() {}
	virtual ~IDBSWebData() {}
	virtual std::string getWebSiteKey() = 0;
	virtual byte *getWebContent() = 0;
};
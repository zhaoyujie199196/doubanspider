#include "DBSDownloader.h"
#include "boost/asio.hpp"

DBSDownloader::DBSDownloader()
{

}

DBSDownloader::~DBSDownloader()
{

}

IDBSDownloader::EnDownCode DBSDownloader::download(const std::string &strWebSite, std::string &webContent)
{
	boost::asio::io_service io_service;
	return DOWN_NO_ERROR;
}
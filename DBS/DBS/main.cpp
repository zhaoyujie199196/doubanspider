#include <iostream>
#include <stdlib.h>
#include"DBSManager.h"
#include "utils/DBSLogTool.h"

int main()
{
	LOG("--------DBSpider begin--------");
	DBSManager dbsManager;
	dbsManager.init();
	dbsManager.exec();
	system("pause");
	return 0;
}
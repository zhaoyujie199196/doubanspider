#include <iostream>
#include <stdlib.h>
#include"DBSManager.h"

int main()
{
	DBSManager dbsManager;
	dbsManager.init();
	dbsManager.exec();
	system("pause");
	return 0;
}
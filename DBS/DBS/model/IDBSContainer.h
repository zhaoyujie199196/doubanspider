#pragma once

//����������һ���������һ���ض�������

#include <memory>

class IDBSItem;
class IDBSContainer
{
public:
	IDBSContainer() {}
	virtual ~IDBSContainer() {}
	//���ݼ�ֵ��������
	virtual std::shared_ptr<IDBSItem> getItem(const std::string &strKey) = 0;
	//�������
	virtual addItem(std::shared_ptr<IDBSItem> pItem) = 0;
};
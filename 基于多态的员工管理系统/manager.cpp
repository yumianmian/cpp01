#include "manager.h"

cmanager::cmanager(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cmanager::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->mname
		<< "\tְ����λ��" << this->getdeptname()
		<< "\t��λְ����ɾ�����������"
		<< endl;
}

string cmanager::getdeptname() {
	return "����";
}
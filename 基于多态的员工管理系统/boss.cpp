#include "boss.h"

cboss::cboss(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cboss::showinfo() {
	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->mname
		<< "\tְ����λ��" << this->getdeptname()
		<< "\t��λְ�𣺹���˾����"
		<< endl;
}

string cboss::getdeptname() {
	return "�ϰ�";
}
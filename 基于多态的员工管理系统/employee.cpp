#include "employee.h"

cemployee::cemployee(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cemployee::showinfo() {

	cout << "ְ����ţ�" << this->mid
		<< "\tְ��������" << this->mname
		<< "\tְ����λ��" << this->getdeptname()
		<< "\t��λְ������ϰ彻���������·���Ա������"
		<< endl;
}

string cemployee::getdeptname() {

	return "Ա��";
}
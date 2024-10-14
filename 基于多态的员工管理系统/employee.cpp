#include "employee.h"

cemployee::cemployee(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cemployee::showinfo() {

	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->mname
		<< "\t职工岗位：" << this->getdeptname()
		<< "\t岗位职责：完成老板交给的任务并下发给员工任务"
		<< endl;
}

string cemployee::getdeptname() {

	return "员工";
}
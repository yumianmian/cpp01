#include "manager.h"

cmanager::cmanager(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cmanager::showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->mname
		<< "\t职工岗位：" << this->getdeptname()
		<< "\t岗位职责：完成经理交给的任务"
		<< endl;
}

string cmanager::getdeptname() {
	return "经理";
}
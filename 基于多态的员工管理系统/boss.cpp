#include "boss.h"

cboss::cboss(int id, string name, int did) {
	this->mid = id;
	this->mname = name;
	this->mdeptid = did;
}

void cboss::showinfo() {
	cout << "职工编号：" << this->mid
		<< "\t职工姓名：" << this->mname
		<< "\t职工岗位：" << this->getdeptname()
		<< "\t岗位职责：管理公司事务"
		<< endl;
}

string cboss::getdeptname() {
	return "老板";
}
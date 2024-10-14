#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (ifs.is_open()) {

	}
	else {
		this->peopletotal = 0;
		this->peopletotalarr = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->peopletotal = 0;
		this->peopletotalarr = NULL;
		this->fileisempty = true;
		ifs.close();
		return;
	}

	int num = this->getpeopletotal();
	cout << "*********当前有" << num << "个职工************" << endl;
	this->peopletotal = num;

	this->peopletotalarr = new cworker * [this->peopletotal];
	this->initemp();

	/*for (int i = 0; i < this->peopletotal; i++) {
		cout << "编号：" << this->peopletotalarr[i]->mid << " "
			<< "姓名：" << this->peopletotalarr[i]->mname << " "
			<< "职位:" << this->peopletotalarr[i]->getdeptname()
			<< endl;
	}*/
}

WorkerManager::~WorkerManager() {
	if (this->peopletotalarr != NULL) {
		delete[] this->peopletotalarr;
		this->peopletotalarr = NULL;
	}
}

void WorkerManager::show_memu() {

	cout << "***************************************" << endl;
	cout << "******** 欢迎使用职工管理系统 ***********" << endl;
	cout << "******** 0.退出 ************************" << endl;
	cout << "******** 1.增加 ************************" << endl;
	cout << "******** 2.显示 ************************" << endl;
	cout << "******** 3.删除 ************************" << endl;
	cout << "******** 4.修改 ************************" << endl;
	cout << "******** 5.查找 ************************" << endl;
	cout << "******** 6.排序 ************************" << endl;
	cout << "******** 7.清空 ************************" << endl;
	cout << "***************************************" << endl;
	
}

void WorkerManager::exitsystem() {

	cout << "-----欢迎下次使用-----" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addemp() {

	cout << "请输入添加人数：" << endl;
	int addtotal;
	cin >> addtotal;

	if (addtotal <= 0) {
		cout << "error" << endl;
		system("pause");
		system("cls");
	}
	else {
		
		int newsize = this->peopletotal + addtotal;
		cworker** newspace = new cworker * [newsize];

		if (this->peopletotalarr != NULL) {
			for (int i = 0; i < this->peopletotal; i++)
			{
				newspace[i] = this->peopletotalarr[i];
			}
		}

		for (int i = 0; i < addtotal; i++) {
			int id;
			string name;
			int did;

			cout << "请输入编号：" << endl;
			cin >> id;
			cout << "请输入姓名：" << endl;
			cin >> name;
			cout << "请选择部门（1员工，2经理，3老板）:" << endl;
			cin >> did;

			cworker* worker = NULL;
			switch (did) {
			case 1:
				worker = new cemployee(id, name, did);
				break;
			case 2:
				worker = new cmanager(id, name, did);
				break;
			case 3:
				worker = new cboss(id, name, did);	
				break;	
			default:
				break;
			}

			newspace[this->peopletotal + i] = worker;
		}

		delete[] this->peopletotalarr;
		this->peopletotalarr = newspace;
		this->peopletotal = newsize;

		this->save();
		cout << "成功添加人数：" << addtotal << endl;
		this->fileisempty = false;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save() {

	ofstream ofs;
	ofs.open(filename, ios::out);

	for (int i = 0; i < this->peopletotal; i++) {
		ofs << this->peopletotalarr[i]->mid << "  "
			<< this->peopletotalarr[i]->mname << "  "
			<< this->peopletotalarr[i]->mdeptid << "  "
			<< endl;
	}

	ofs.close();
}

int WorkerManager::getpeopletotal() {
	ifstream ifs;
	ifs.open(filename, ios::in);
	int num = 0;

	int id;
	string name;
	int did;
	while (ifs >> id && ifs >> name && ifs >> did) {
		num++;
	}

	return num;
}

void WorkerManager::initemp() {

	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did) {

		cworker* worker = NULL;

		if (did == 1) {
			worker = new cemployee(id, name, did);
		}
		else if (did == 2) {
			worker = new cmanager(id, name, did);
		}
		else {
			worker = new cboss(id, name, did);
		}

		
		this->peopletotalarr[index] = worker;
		index++;
	}

	ifs.close();
}

void WorkerManager::showemp() {

	if (this->fileisempty) {
		cout << "file is empty or file is null" << endl;
	}
	else {
		for (int i = 0; i < this->peopletotal; i++) {
			this->peopletotalarr[i]->showinfo();
		}
	}

	system("pause");
	system("cls");
}

int WorkerManager::isexist(int id) {

	int index = -1;
	for (int i = 0; i < this->peopletotal; i++) {
		if (this->peopletotalarr[i]->mid == id) {
			index = i;
			break;
		}
	}
	
	return index;
}

void WorkerManager::deleteemp() {

	if (this->fileisempty) {
		cout << "file is empty or null" << endl;
	}
	else {
		int empid;
		cout << "请输入需要删除的职工编号： ";
		cin >> empid;
		int isexist = this->isexist(empid);
		if (isexist == -1) {
			cout << "职工不存在.." << endl;
		}
		else {
			for (int i = isexist; i < (this->peopletotal)-1; i++) {
				this->peopletotalarr[i] = this->peopletotalarr[i + 1];
			}
			this->peopletotal--;
			this->save();
			cout << "删除成功" << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::modifyemp() {
	if (this->fileisempty) {
		cout << "file is empty or null" << endl;
	}
	else {
		int empid;
		cout << "请输入需要修改的职工编号： ";
		cin >> empid;
		int isexist = this->isexist(empid);
		if (isexist == -1) {
			cout << "职工不存在.." << endl;
		}
		else {
			delete this->peopletotalarr[isexist];

			cout << "请重新输入此职工信息(依次输入编号姓名岗位)：" << endl;
			int id;
			string name;
			int did;

			cin >> id >> name >> did;

			cworker* worker = NULL;

			switch (did) {
			case 1:
				worker = new cemployee(id, name, did);
				break;
			case 2:
				worker = new cmanager(id, name, did);
				break;
			case 3:
				worker = new cboss(id, name, did);
				break;
			default:
				cout << "输入了不存在的岗位.." << endl;
				break;
			}

			this->peopletotalarr[isexist] = worker;
			this->save();
			
			cout << "修改成功" << endl;
		}
	}

	system("pause");
	system("cls");
}
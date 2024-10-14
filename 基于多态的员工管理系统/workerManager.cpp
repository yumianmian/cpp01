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
	cout << "*********��ǰ��" << num << "��ְ��************" << endl;
	this->peopletotal = num;

	this->peopletotalarr = new cworker * [this->peopletotal];
	this->initemp();

	/*for (int i = 0; i < this->peopletotal; i++) {
		cout << "��ţ�" << this->peopletotalarr[i]->mid << " "
			<< "������" << this->peopletotalarr[i]->mname << " "
			<< "ְλ:" << this->peopletotalarr[i]->getdeptname()
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
	cout << "******** ��ӭʹ��ְ������ϵͳ ***********" << endl;
	cout << "******** 0.�˳� ************************" << endl;
	cout << "******** 1.���� ************************" << endl;
	cout << "******** 2.��ʾ ************************" << endl;
	cout << "******** 3.ɾ�� ************************" << endl;
	cout << "******** 4.�޸� ************************" << endl;
	cout << "******** 5.���� ************************" << endl;
	cout << "******** 6.���� ************************" << endl;
	cout << "******** 7.��� ************************" << endl;
	cout << "***************************************" << endl;
	
}

void WorkerManager::exitsystem() {

	cout << "-----��ӭ�´�ʹ��-----" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::addemp() {

	cout << "���������������" << endl;
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

			cout << "�������ţ�" << endl;
			cin >> id;
			cout << "������������" << endl;
			cin >> name;
			cout << "��ѡ���ţ�1Ա����2����3�ϰ壩:" << endl;
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
		cout << "�ɹ����������" << addtotal << endl;
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
		cout << "��������Ҫɾ����ְ����ţ� ";
		cin >> empid;
		int isexist = this->isexist(empid);
		if (isexist == -1) {
			cout << "ְ��������.." << endl;
		}
		else {
			for (int i = isexist; i < (this->peopletotal)-1; i++) {
				this->peopletotalarr[i] = this->peopletotalarr[i + 1];
			}
			this->peopletotal--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
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
		cout << "��������Ҫ�޸ĵ�ְ����ţ� ";
		cin >> empid;
		int isexist = this->isexist(empid);
		if (isexist == -1) {
			cout << "ְ��������.." << endl;
		}
		else {
			delete this->peopletotalarr[isexist];

			cout << "�����������ְ����Ϣ(����������������λ)��" << endl;
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
				cout << "�����˲����ڵĸ�λ.." << endl;
				break;
			}

			this->peopletotalarr[isexist] = worker;
			this->save();
			
			cout << "�޸ĳɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}
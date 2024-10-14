#include "iostream"
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;


int main() {


	/*cworker* cworker = NULL;
	cworker = new cemployee(1, "zhangsan", 1);
	cworker->showinfo();
	delete cworker;

	cworker = new cmanager(2, "zhangsan", 2);
	cworker->showinfo();
	delete cworker;

	cworker = new cboss(1, "zhangsan", 1);
	cworker->showinfo();
	delete cworker;*/

	WorkerManager wm;

	int choice;

	while (1) {

		

		wm.show_memu();

		cout << "-----请输入数字选择操作-----" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			wm.exitsystem();
			break;
		case 1:
			wm.addemp();
			break;
		case 2:
			wm.showemp();
			break;
		case 3:
			wm.deleteemp();
			break;
		case 4:
			wm.modifyemp();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}
	}

	


	

	return 0;
}
#pragma	once
#include"iostream"
#include"string"
#include "worker.h"

using namespace std;

class cboss : public cworker {
public:

	cboss(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};
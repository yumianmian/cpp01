#pragma once
#include "iostream"
#include "string"
#include "worker.h"

using namespace std;

class cmanager : public cworker {
public:

	cmanager(int id, string name, int did);
	virtual void showinfo();
	virtual string getdeptname();
};
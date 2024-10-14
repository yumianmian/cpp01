#pragma	once
#include"iostream"
#include"string"
#include "worker.h"

using namespace std;

class cemployee :public cworker {
public:

	cemployee(int id,string name,int did);
	void showinfo();
	string getdeptname();
};
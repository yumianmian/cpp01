#pragma	once
#include"iostream"
#include"string"

using namespace std;


class cworker {
public:

	virtual void showinfo() = 0;
	virtual string getdeptname() = 0;

	int mid;
	string mname;
	int mdeptid;
};

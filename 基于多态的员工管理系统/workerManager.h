#pragma once
#include "iostream"
#include "worker.h"
#include "fstream"

#define filename "hh.txt"

using namespace std;


class WorkerManager {
public:

	WorkerManager();

	void show_memu();

	void exitsystem();

	void addemp();

	void save();

	int getpeopletotal();

	void initemp();

	void showemp();

	int isexist(int id);

	void deleteemp();

	void modifyemp();





	int peopletotal;

	cworker** peopletotalarr;

	bool fileisempty;

	~WorkerManager();
};
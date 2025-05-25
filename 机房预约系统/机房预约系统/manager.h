#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager : public Identity
{
public:
	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

	void initVector();

	bool checkRepeat(int id, int type);

	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void sCom();

	void showComputer();

	void cleanFile();

};
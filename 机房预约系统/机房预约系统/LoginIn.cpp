#include "globalFile.h"
#include"identity.h"
#include<fstream>
#include<string>


void LoginIn(string fileName, int type)
{
	Identity * person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登陆验证
	}
	else if (type == 2)
	{
		//教师登陆验证
	}
	else if (type == 3)
	{
		//管理员登陆验证
	}


	cout << "登陆验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}

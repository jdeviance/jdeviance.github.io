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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ��
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����½��֤
	}
	else if (type == 2)
	{
		//��ʦ��½��֤
	}
	else if (type == 3)
	{
		//����Ա��½��֤
	}


	cout << "��½��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

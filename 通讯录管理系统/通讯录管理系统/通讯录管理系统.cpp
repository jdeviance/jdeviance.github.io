#include<iostream>
#include<string>
using namespace std;
const int  Max = 1000;
struct Person{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;

};
struct Addressbooks
{
	Person personArray[Max];
	int m_Size = 0;
};

void addPerson(Addressbooks * abs)
{
	if (abs->m_Size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << '\n';
		return;
	 }
	else//�����Ա�����绰
	{
		//����
		string name;
		cout << "������������" << '\n';
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << '\n';
		cout << "0 --- ��" << '\n';
		cout << "1 --- Ů" << '\n';
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << '\n';
		}
		//����
		int age;
		cout << "���������䣺" << '\n';
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		string phone;
		cout << "��������ϵ�绰��" << '\n';
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		string  address;
		cout << "�������ͥסַ��" << '\n';
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//��������
		abs->m_Size++;

		cout << "��ӳɹ�" << '\n';
		system("pause");
		system("cls");
		
	}
}

void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << '\n';
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "������" << abs->personArray[i].m_Name << '\t';
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ?"Ů" : "��") << '\t';
			cout << "���䣺" << abs->personArray[i].m_Age << '\t';
			cout << "��ϵ�绰��" << abs->personArray[i].m_Phone << '\t';
			cout << "��ͥסַ��" << abs->personArray[i].m_Addr<< '\n'; 
		}
		system("pause");
		system("cls");
	}
}

int isExist(Addressbooks* abs , string name) 
{
	for (int i = 0;i < abs->m_Size;i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
		string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret;i < abs->m_Size;i++) 
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << '\n';
	}
	else cout << "���޴��ˣ�" << '\n';
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << '\t';
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "Ů" : "��") << '\t';
		cout << "���䣺" << abs->personArray[ret].m_Age << '\t';
		cout << "��ϵ�绰��" << abs->personArray[ret].m_Phone << '\t';
		cout << "��ͥסַ��" << abs->personArray[ret].m_Addr << '\n';
	}
	else cout << "���޴��ˣ�" << '\n';
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
			string name;
			cout << "������������" << '\n';
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;
			cout << "�������Ա�" << '\n';
			cout << "0 --- ��" << '\n';
			cout << "1 --- Ů" << '\n';
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 0 || sex == 1)
				{
					abs->personArray[ret].m_Sex = sex;
					break;
				}
				cout << "������������������" << '\n';
			}
			int age;
			cout << "���������䣺" << '\n';
			cin >> age;
			abs->personArray[ret].m_Age = age;
			string phone;
			cout << "��������ϵ�绰��" << '\n';
			cin >> phone;
			abs->personArray[ret].m_Phone = phone;
			string  address;
			cout << "�������ͥסַ��" << '\n';
			cin >> address;
			abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ���" << '\n';
	}
	else cout << "���޴��ˣ�" << '\n';
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pasue");
	system("cls");
}

void showMenu() {
	cout << "***********************" << '\n';
	cout << "*****1�������ϵ��*****" << '\n';
	cout << "*****2����ʾ��ϵ��*****" << '\n';
	cout << "*****3��ɾ����ϵ��*****" << '\n';
	cout << "*****4��������ϵ��*****" << '\n';
	cout << "*****5���޸���ϵ��*****" << '\n';
	cout << "*****6�������ϵ��*****" << '\n';
	cout << "*****0���Ƴ�ͨѶ¼*****" << '\n';
	cout << "***********************" << '\n';
}

int  main() 
{
	Addressbooks abs;

	abs.m_Size = 0;
	int select = 0;
	while (true) 
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
		/*	{
				cout << "������ɾ����ϵ�˵�������" << '\n';
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
				{
					cout << "���޴��ˣ�" << '\n';
					system("pause");
					system("cls");
				}
				else cout << "�ҵ�����" << '\n';
			}*/
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0://0���Ƴ�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << '\n';
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");

	return 0;
}
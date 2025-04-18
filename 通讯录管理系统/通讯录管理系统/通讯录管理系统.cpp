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
		cout << "通讯录已满，无法添加！" << '\n';
		return;
	 }
	else//姓名性别年龄电话
	{
		//姓名
		string name;
		cout << "请输入姓名：" << '\n';
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别：" << '\n';
		cout << "0 --- 男" << '\n';
		cout << "1 --- 女" << '\n';
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << '\n';
		}
		//年龄
		int age;
		cout << "请输入年龄：" << '\n';
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		string phone;
		cout << "请输入联系电话：" << '\n';
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		string  address;
		cout << "请输入家庭住址：" << '\n';
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新人数
		abs->m_Size++;

		cout << "添加成功" << '\n';
		system("pause");
		system("cls");
		
	}
}

void showPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << '\n';
	}
	else
	{
		for (int i = 0;i < abs->m_Size;i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << '\t';
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ?"女" : "男") << '\t';
			cout << "年龄：" << abs->personArray[i].m_Age << '\t';
			cout << "联系电话：" << abs->personArray[i].m_Phone << '\t';
			cout << "家庭住址：" << abs->personArray[i].m_Addr<< '\n'; 
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
	cout << "请输入您要删除的联系人：" << endl;
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
		cout << "删除成功！" << '\n';
	}
	else cout << "查无此人！" << '\n';
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << '\t';
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "女" : "男") << '\t';
		cout << "年龄：" << abs->personArray[ret].m_Age << '\t';
		cout << "联系电话：" << abs->personArray[ret].m_Phone << '\t';
		cout << "家庭住址：" << abs->personArray[ret].m_Addr << '\n';
	}
	else cout << "查无此人！" << '\n';
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
			string name;
			cout << "请输入姓名：" << '\n';
			cin >> name;
			abs->personArray[abs->m_Size].m_Name = name;
			cout << "请输入性别：" << '\n';
			cout << "0 --- 男" << '\n';
			cout << "1 --- 女" << '\n';
			int sex = 0;
			while (true)
			{
				cin >> sex;
				if (sex == 0 || sex == 1)
				{
					abs->personArray[ret].m_Sex = sex;
					break;
				}
				cout << "输入有误，请重新输入" << '\n';
			}
			int age;
			cout << "请输入年龄：" << '\n';
			cin >> age;
			abs->personArray[ret].m_Age = age;
			string phone;
			cout << "请输入联系电话：" << '\n';
			cin >> phone;
			abs->personArray[ret].m_Phone = phone;
			string  address;
			cout << "请输入家庭住址：" << '\n';
			cin >> address;
			abs->personArray[ret].m_Addr = address;
		cout << "修改成功！" << '\n';
	}
	else cout << "查无此人！" << '\n';
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pasue");
	system("cls");
}

void showMenu() {
	cout << "***********************" << '\n';
	cout << "*****1、添加联系人*****" << '\n';
	cout << "*****2、显示联系人*****" << '\n';
	cout << "*****3、删除联系人*****" << '\n';
	cout << "*****4、查找联系人*****" << '\n';
	cout << "*****5、修改联系人*****" << '\n';
	cout << "*****6、清空联系人*****" << '\n';
	cout << "*****0、推出通讯录*****" << '\n';
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
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
		/*	{
				cout << "请输入删除联系人的姓名：" << '\n';
				string name;
				cin >> name;
				if (isExist(&abs, name) == -1)
				{
					cout << "查无此人！" << '\n';
					system("pause");
					system("cls");
				}
				else cout << "找到此人" << '\n';
			}*/
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modifyPerson(&abs);
			break;
		case 6://6、清空联系人
			cleanPerson(&abs);
			break;
		case 0://0、推出通讯录
			cout << "欢迎下次使用" << '\n';
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
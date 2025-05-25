#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data; //���� 
	node* next; //ָ�� 
};

node* head = NULL;

void init_node();//��ʼ�� 
void head_insert(int);//ͷ�巨 
void end_insert(int);//β�巨 
void delete_node(int);//ɾ��Ԫ�� 
void show();//���� 

int main()
{
	
	init_node();
 	head_insert(4);
 	head_insert(9);
 	end_insert(7);
 	show();
 	delete_node(7);
 	show();
}

void init_node()
{
	node* new_node = new node;//����һ����Ϊnew_node �� node 
	new_node ->data =-1;//������˸�-1
	new_node ->next = NULL;
	head = new_node;
}

void head_insert(int key)
{
	node * new_node = new node;
	new_node ->data = key;
	
	new_node ->next = head->next;
	
	head -> next = new_node; 
}

void end_insert(int key)
{
	node * new_node = new node;
	node *temp = head;
	while(temp->next != NULL)
		temp = temp ->next;
	new_node->data = key;
	new_node->next = temp->next;
	temp ->next = new_node; 
		
}

void delete_node(int key)
{
	node* temp = head -> next;
	node* prev = head;
	while(temp != NULL && temp->data!=key)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp == NULL)
	{
		cout <<"û�д˽ڵ�"<<endl;
		return; 
	}
	prev -> next = temp->next;
	temp -> next =NULL;
	delete temp;
	temp = NULL;
}

void show()
{
	node *temp = head->next;
	if(temp == NULL)
	{
		cout << "��û�д����ڵ�" << endl;
	}
	while(temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp ->next;
	}
	cout << endl;
}



















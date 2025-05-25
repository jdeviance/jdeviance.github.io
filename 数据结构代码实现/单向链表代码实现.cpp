#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data; //数据 
	node* next; //指针 
};

node* head = NULL;

void init_node();//初始化 
void head_insert(int);//头插法 
void end_insert(int);//尾插法 
void delete_node(int);//删除元素 
void show();//遍历 

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
	node* new_node = new node;//创建一个名为new_node 的 node 
	new_node ->data =-1;//里面存了个-1
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
		cout <<"没有此节点"<<endl;
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
		cout << "还没有创建节点" << endl;
	}
	while(temp != NULL)
	{
		cout << temp->data << ' ';
		temp = temp ->next;
	}
	cout << endl;
}



















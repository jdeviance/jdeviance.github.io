#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* front;
	Node* next;
};

Node* head;
Node* last;

void initnode(int);
void head_insert(int);
void end_insert(int);
void delete_node(int);
void show();

int main()
{
	initnode(1);
	head_insert(5);
	head_insert(2);
	end_insert(3);
	show();
	delete_node(2);
	show();
 } 
 
 void initnode(int key)
 {
	Node *new_node = new Node;
	new_node->val = key;
	head = new Node;
	last = new Node;
	head -> next = new_node;
	last -> front = new_node;
	new_node -> next = last;
	new_node -> front = head;
	head ->val = last ->val = -1;
 }
 
 void head_insert(int key)
 {
	Node *new_node = new Node;
	new_node->val = key;
	new_node->next = head->next;
	new_node->front = head;
	head->next->front = new_node;
	head->next = new_node;
 	
 }
 
 void end_insert(int key)
{
	Node *new_node = new Node;
	new_node->val = key;
	new_node->next = last;
	new_node->front = last->front;
	last->front->next = new_node;
	last->front = new_node;
} 

void delete_node(int key)
{
	Node *temp = head ->next;
	while(temp ->val != key)
	{
		if(temp->val == -1)
		{
			cout << "没有此节点"<<endl;
			return; 
		}
		temp = temp->next;
	}
	Node* Prev = temp->front;
	Node* Next = temp->next;
	Prev->next = Next;
	Next->front = Prev;
	
	temp->front = temp->next = NULL;
	delete[]temp;
	temp = NULL;
}

void show()
{
	Node *temp = head->next;
	if(temp ->val == -1)
	{
		cout <<"当前还没有创建节点" <<endl;
		return;
	}
	
	while(temp ->val != -1)
	{
		cout << temp->val << ' ';
		temp = temp ->next;
		 
	}
	
}


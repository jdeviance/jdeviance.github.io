#include <bits/stdc++.h>
using namespace std;


struct tree_node {
	int data;
	tree_node *next;
};

int Size;			
tree_node *Node[8];		

void init_node(int);
void child_insert(int, int);
int find_node(int);

int main()
{
	init_node(1);
	child_insert(4, 1);
	child_insert(5, 1);
	child_insert(6, 4);
	child_insert(3, 4);
	child_insert(7, 3);
	for (int i = 0; i < Size; i++) {
		cout << "父节点为" << Node[i]->data;
		tree_node *temp_node = Node[i];
		while (temp_node->next != NULL) {
			temp_node = temp_node->next;
			cout << " 孩子节点为" << temp_node->data;
		}
		cout << endl;
	}
	
}

void init_node(int key)
{
	tree_node* new_node = new tree_node;
	new_node->data = key;
	new_node->next =NULL;
	Size = 0;
	Node[Size] = new_node;
	Size++;
}

void child_insert(int key,int parent)
{
	if(Size == 0)
	{
		cout <<"请先创建根节点"<<endl;
	}
	else
	{
		Node[Size] = new tree_node;
		Node[Size] -> data = key;
		Node[Size] -> next = NULL;
		Size++;
		int index =find_node(parent);
		if(index == -){
			cout << "没有该父亲节点" <<endl; 
		}
		else
		{
			tree_node* new_node =  new tree_node;
			new_node -> next = Node[index] ->next;
			new_node -> data = key;
			Node[index] ->next = new_node;
		}
	}
}

int find_node(int parent) {
	for (int i = 0; i < Size; i++) {
		if (Node[i]->data == parent) {
			return i;
		}
	}
	return -1;
}

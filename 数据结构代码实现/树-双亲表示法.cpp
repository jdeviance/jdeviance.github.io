#include<bits/stdc++.h>
using namespace std;


struct tree_node
{
	int data;
	int parent;
};

tree_node* Node[5];
int Size;
int maxSize;

void init_tree();
void root_insert(int);
void child_insert(int,int);
int find_node(int);

int main()
{
	init_tree();
	root_insert(1);
	child_insert(2, 1);
	child_insert(3, 1);
	child_insert(4, 2);
	cout << Node[0]->data << " " << Node[0]->parent<< endl;
	cout << Node[1]->data << " " << Node[1]->parent << endl;
	cout << Node[3]->data << " " << Node[3]->parent << endl;

}


void init_tree() 
{
	Size = 0;
	maxSize = 5;
}


void root_insert(int key)
{
	if(Size != 0){
		cout << "已经创建根节点！"<<endl;
		return;
	}
	tree_node* root_node = new tree_node; 
	root_node->data = key;
	root_node->parent = -1;
	Node[Size++] = root_node;
}

void child_insert(int key,int parent)
{
	if(Size==0)
	{
		cout <<"请先创建根节点"<<endl;
	}
	else if(Size == maxSize)
	{
		cout << "根节点已满"<<endl;
	}
	else
	{
		int parent_index = find_node(parent);
		if(parent_index == -1)
		{
			cout << "没有该父亲节点" << endl;
		} 
		else
		{
			tree_node *child_node = new tree_node;
			child_node->data = key;
			child_node->parent = parent_index;
			Node[Size++] = child_node;
		}
	}
}

int find_node(int parent)
{
	for(int i=0;i<Size;i++)
	{
		if(parent ==Node[i]->data){
			return Node[i]->data;
		}
	}
	return -1;
}

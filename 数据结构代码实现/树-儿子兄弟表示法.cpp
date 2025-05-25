#include<bits/stdc++.h>
using namespace std;

struct tree_node
{
	int data;
	tree_node* child;
	tree_node* sibling;
};

tree_node* root_node = NULL;
tree_node* temp_node = NULL;

void root_init(int);
void child_insert(int,int);
void find_node(tree_node*,int);
void show(tree_node* root_node);

int main()
{
	root_init(1);
	child_insert(2, 1);
	child_insert(3, 1);
	child_insert(4, 2);
	child_insert(6, 4);
	show(root_node);
}

void show(tree_node* root_node)
{
	if(root_node == NULL)
		return;
	cout << root_node->data << ' ';
	show(root_node->sibling);
	show(root_node->child);
}

void root_init(int key)
{
	root_node = new tree_node;
	root_node->data = key;
	root_node->child = NULL;
	root_node->sibling = NULL;
}

void child_insert(int key,int parent)
{
	if(root_node == NULL)
	{
		cout<<"请先创建根节点"<<endl;
		
	}
	else
	{
		temp_node = NULL;
		find_node(root_node,parent);
		if(temp_node == NULL){
			cout<<"没有找到该父节点"<<endl; 
		}
		else
		{
			tree_node* new_node = new tree_node;
			new_node ->data =key;
			new_node ->child = NULL;
			new_node ->sibling = temp_node->child;
			temp_node->child = new_node; 
		}
	}
}

void find_node(tree_node* node,int parent)
{
	if(node->data == parent)
	{
		temp_node = node;
	}
	else
	{
		if(node->sibling !=NULL)
		{
			find_node(node->sibling,parent);
		}
		if(node->child !=NULL)
		{
			find_node(node->child,parent);
		}
	}
}





































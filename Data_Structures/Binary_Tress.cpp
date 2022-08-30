/*
 * =====================================================================================
 *
 *       Filename:  Binary_Tress.cpp
 *
 *    Description:  Implementation of Binary Trees in C++  
 *
 *        Version:  1.0
 *        Created:  29/08/22 11:54:01 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  NULL
 *
 * =====================================================================================
 *
*/
 

/* 
 ________________________________________________________________________________________

 If empty tree is created without input then there are two options:
 1. Make value null and update value when add_node is used instead of creating a new node
 2. Make value 0 
 Here second method is implemented.

 There are two ways to handle leafs of tree:
 1. Either leaves point to NULL pointer
 2. Or leaves point to nodes with some particular reserved value
 Here first method is implemented.
 _________________________________________________________________________________________

*/

#include<iostream>
#include<bits/stdc++.h>

int const MAX_SIZE = 25;   // for traversal purposes

/* ______________definitions________________ */

/* _______node__definition_______ */


struct node
{
	int value;
	node* parent ;
	node* left;
	node* right;
};



/* _________binary__tree__class__interfaece________ */


class bt
{

 public:

	bt();
	bt(int root_value);
	~bt();

	void add_node(int node_value);
	void del_node(int node_value);

	bool is_node_present(int node_value);

	void inorder_traversal(node * NODE);
	void preorder_traversal(node * NODE);
	void postorder_traversal(node * NODE);

	node* get_root_pointer();
	int get_tree_size();	
	int get_root_value();
	

 private:

	node *root = new node;
	node *current_node = new node;
	node *current2_node = new node;
	int tree_size = 0;
};


/* ________class__bt__methods__defintions________ */

bt::bt()
{
	tree_size=1;

	root = new node;
	root->value = 0;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	current_node = root;
	current2_node = root;
}

bt::bt(int root_value)
{
	tree_size=1;

	root = new node;
	root->value = root_value;
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	current_node = root;
	current2_node = root;
}

bool is_deleted[MAX_SIZE]={0};

bt::~bt()
{
	while(root->left != NULL && !(is_deleted[root->left->value]))
	{
		postorder_traversal(root->left);
	}	

	while(root->right != NULL && !(is_deleted[root->right->value]))
	{
		postorder_traversal(root->right);
	}

	delete root;
	is_deleted[root->value]=1;
	tree_size--;
}


node* bt::get_root_pointer()
{
	return root;
}

int bt::get_root_value()
{
	return root->value;
}


void bt::add_node(int node_value)
{
	if(node_value <= current_node->value)
	{
		if(current_node->left == NULL)
		{
			node *nodeL = new node;
			current_node->left = nodeL;
			nodeL->value = node_value;
			nodeL->left = NULL;
			nodeL->right = NULL;
			nodeL->parent = current_node;
			tree_size++;
			current_node = root;
		}
		else if(current_node != NULL)
		{
			current_node = current_node->left;
			add_node(node_value);
		}
	}
	else if(node_value > current_node->value)
	{
		if(current_node->right == NULL)
		{
			node *nodeR = new node;
			current_node->right = nodeR;
			nodeR->value = node_value;
			nodeR->left = NULL;
			nodeR->right = NULL;
			nodeR->parent = current_node;
			tree_size++;
			current_node = root;
		}
		else if(current_node != NULL)
		{
			current_node = current_node->right;
			add_node(node_value);
		}
	}
}

bool bt::is_node_present(int node_value)
{

	if(node_value < current_node->value)
	{
		if(current_node->left == NULL)
		{
			current_node = root;
			return false;
		}
		else
		{
			current_node = current_node->left;
			is_node_present(node_value);
		}
	}
	else if(node_value > current_node->value)
	{
		if(current_node->right == NULL)
		{
			current_node = root;
			return false;
		}
		else
		{
			current_node = current_node->right;
			is_node_present(node_value);
		}
	}
	else if(node_value == current_node->value)
	{
		current2_node = current_node;
		current_node = root;
		return true;
	}
	else
	{
		return false;
	}
}


//----del  node  helper  funtion----------for__special__2__children__case---------//

node* getMinimumKey(node* curr)
{
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

//------------for__special__2__children__case---------//

void bt::del_node(int node_value)
{
	if(node_value<(current_node->value))	
	{
		current_node = current_node->left;
		del_node(node_value);
	}
	else if(node_value>(current_node->value))	
	{
		current_node = current_node->right;
		del_node(node_value);
	}
	else if(node_value==current_node->value)	
	{

		if(current_node->left != NULL && current_node->right != NULL )
		{

		struct node*  iter = current_node;

		if(current_node->parent->left == current_node)
			current_node->parent->left = iter;
		else
			current_node->parent->right = iter;

		current_node->left->parent = iter;
		current_node->left->parent = iter;

        node* successor = getMinimumKey(current_node->right);
 

        int val = successor->value;
 
		current_node->left->parent = iter;
		current_node->left->parent = iter;


        del_node(successor->value);
 
        iter->value = val;


		}
		else if(current_node->left == NULL && current_node->right != NULL )
		{
			if(current_node->parent->left == current_node)
				current_node->parent->left = current_node->right;
			else
				current_node->parent->right = current_node->right;

			current_node = root;
			tree_size--;	
		}
		else if(current_node->left != NULL && current_node->right == NULL )
		{
			if(current_node->parent->left == current_node)
				current_node->parent->left = current_node->left;
			else
				current_node->parent->right = current_node->left;

			current_node = root;
			tree_size--;	
		}
		else if(current_node->left == NULL && current_node->left == NULL )
		{
			if(current_node->parent->left == current_node)
				current_node->parent->left = NULL;
			else
				current_node->parent->right = NULL;

			current_node = root;
			tree_size--;
		}
	}
}



int bt::get_tree_size()
{
	return tree_size;
}


/*__________traversal__functions_____________*/

bool is_visited[MAX_SIZE]={0};

void preorder_traversal(node* NODE)
{
	std::cout<<NODE->value<<'\n';
	is_visited[NODE->value]=1;

	
	while(NODE->left != NULL && !(is_visited[NODE->left->value]))
	{
		preorder_traversal(NODE->left);
	}

	while(NODE->right != NULL && !(is_visited[NODE->right->value]))
	{
		preorder_traversal(NODE->right);
	}	
}

void postorder_traversal(node* NODE)
{

	while(NODE->left != NULL && !(is_visited[NODE->left->value]))
	{
		postorder_traversal(NODE->left);
	}	

	while(NODE->right != NULL && !(is_visited[NODE->right->value]))
	{
		postorder_traversal(NODE->right);
	}

	std::cout<<NODE->value<<'\n';
	is_visited[NODE->value]=1;
}

void inorder_traversal(node* NODE)
{
	while(NODE->left != NULL && !(is_visited[NODE->left->value]))
	{
		inorder_traversal(NODE->left);
	}

	std::cout<<NODE->value<<'\n';
	is_visited[NODE->value]=1;

	while(NODE->right != NULL && !(is_visited[NODE->right->value]))
	{
		inorder_traversal(NODE->right);
	}	
}


/* _________main__function________ */

int main()
{


bt tree(10);

tree.add_node(5);

tree.add_node(15);

tree.add_node(3);

tree.add_node(8);

tree.add_node(1);

tree.add_node(4);

tree.add_node(7);

tree.add_node(9);

tree.add_node(13);

tree.add_node(18);

tree.add_node(12);

tree.add_node(14);

tree.add_node(17);

tree.add_node(19);


return 0;
}

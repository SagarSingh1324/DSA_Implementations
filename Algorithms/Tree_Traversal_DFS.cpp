/*
 * =====================================================================================
 *
 *       Filename:  Tree_Traversal_DFS.cpp
 *
 *    Description:  Traversing a tree using Depth First Search 
 *
 *        Version:  1.0
 *        Created:  27/08/22 09:02:02 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sagar Singh (SagarSingh1324), sagarsinghprj@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int is_visited[15]={0};

vector<int> edge[10];


void tree_traverse(int index)
{

is_visited[index]=1;

for(auto iter: edge[index])
{

	if(!is_visited[iter])	
	{
		tree_traverse(iter);
	}
}
}


int main()
{

// edge list defintion of tree

edge[1].push_back(2);

edge[1].push_back(3);

edge[1].push_back(4);

edge[2].push_back(1);

edge[2].push_back(5);

edge[2].push_back(6);

edge[3].push_back(1);

edge[4].push_back(1);

edge[4].push_back(7);

edge[5].push_back(2);

edge[6].push_back(2);

edge[6].push_back(8);

edge[7].push_back(4);

edge[8].push_back(6);



// function call

tree_traverse(3);


cout<<"build successful"<<endl;

//cout<<is_visited[1]<<endl
//<<is_visited[2]<<endl
//<<is_visited[3]<<endl
//<<is_visited[4]<<endl
//<<is_visited[5]<<endl
//<<is_visited[6]<<endl
//<<is_visited[7]<<endl
//<<is_visited[8]<<endl;

return 0;
}

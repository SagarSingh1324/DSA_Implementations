#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// declaring the graph
// using adjacenecy list representation

vector<int> adj[15];


// declaring the bfs search function

int is_visited[10]={0};

queue<int> temp;

void visit_bfs(int ind)
{

temp.push(ind);

while(!temp.empty())
{
	for(auto itr: adj[temp.front()])
	{	
		if(is_visited[itr]==0)
		{	
			temp.push(itr);
		}
	}

	is_visited[temp.front()]=1;

	temp.pop();
}
}


int main()
{

// adding graph nodes

adj[1].push_back(2);

adj[1].push_back(3);

adj[1].push_back(5);

adj[2].push_back(1);

adj[2].push_back(5);

// new additions

adj[2].push_back(4);

adj[3].push_back(1);

adj[3].push_back(4);

adj[4].push_back(2);

adj[4].push_back(3);

adj[4].push_back(5);

adj[5].push_back(1);

adj[5].push_back(2);

adj[5].push_back(4);

adj[2].push_back(6);

adj[6].push_back(2);


// calling the function on adj

visit_bfs(1);

cout<<"build successsful"<<endl;


return 0;
}

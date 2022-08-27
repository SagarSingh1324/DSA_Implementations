#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// to check if the given graph is bipartite


// adjacency list graph declaration

vector<int> adj[10];

// function to check if graph is bipartite

int is_visited[10];

int k=0;

void is_bip(int ind)
{

queue<int> temp;
temp.push(ind);

adj[temp.front()].push_back(50);


while(!temp.empty())
{


	for(vector<int>::iterator  itr = adj[temp.front()].begin(); itr<(adj[temp.front()].end()-1); itr++)
	{
		if(!is_visited[*itr])
		{ 	temp.push(*itr);
		
			if(adj[temp.front()].back()==50)
			adj[*itr].push_back(100);
			else if(adj[temp.front()].back()==100)
			adj[*itr].push_back(50);
		}

		if(adj[*itr].back()==adj[temp.front()].back())
		{
			k++;
			break;	
		}
	}	

	is_visited[temp.front()]=1;
	temp.pop();	
}
}



int main()
{

// bipartite graph

adj[1].push_back(2);

adj[1].push_back(4);

adj[2].push_back(1);

adj[2].push_back(3);

adj[2].push_back(5);

adj[3].push_back(2);

adj[4].push_back(1);

adj[5].push_back(2);

adj[5].push_back(6);

adj[6].push_back(5);
 
// to make not bipartite

//adj[1].push_back(3);
//adj[3].push_back(1);
//adj[2].push_back(6);
//adj[6].push_back(2);

// function call


is_bip(1);


//if(k==0)
//cout<<"this graph is bipartite"<<endl;
//else if(k!=0)
//cout<<"this graph is not bipartite"<<endl;


cout<<"build successful"<<endl;

return 0;
}

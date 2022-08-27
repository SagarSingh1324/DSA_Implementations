#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// declaring the graph
// direcred

vector<int> adj[10];


// declaring the function

bool is_visited[10]={0};

void visit_dfs(int ind)
{
        if(is_visited[ind])
        {
                return;
        }
        else
        {
                is_visited[ind]=1;

                for(auto itr: adj[ind])
                {
                        visit_dfs(itr);
                }
        }
}




int main()
{

adj[1].push_back(2);
  
adj[1].push_back(3);
 
adj[1].push_back(5);
  
adj[2].push_back(1);
 
adj[2].push_back(5);

adj[2].push_back(4);

adj[3].push_back(1);

adj[3].push_back(4);

adj[4].push_back(2);

adj[4].push_back(3);

adj[4].push_back(5);

adj[5].push_back(1);

adj[5].push_back(2);

adj[5].push_back(4);



// now implementing DFS

visit_dfs(1);

cout<<"build succesfull"<<endl;


return 0;
}

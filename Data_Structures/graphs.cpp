#include<iostream>
#include<bits/stdc++.h>

// implementation of graphs

using namespace std;

int main()
{

// directed graphs


// adjacency list

vector<int> adj_list[10];

adj_list[1].push_back(2);

adj_list[2].push_back(3);

adj_list[2].push_back(4);

adj_list[3].push_back(4);

adj_list[4].push_back(1);



// adjacency list for undirected graph

vector<int> und_adj_list[10];

und_adj_list[1].push_back(1);

und_adj_list[1].push_back(4);

und_adj_list[2].push_back(1);

und_adj_list[2].push_back(3);

und_adj_list[2].push_back(4);

und_adj_list[3].push_back(2);

und_adj_list[3].push_back(4);

und_adj_list[4].push_back(1);

und_adj_list[4].push_back(2);

und_adj_list[4].push_back(3);




// adjacency matrix

int adj_matrix[4][4] = {{0,1,0,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,0}};


// adjacency matrix for undirected graph


int undir_adj_matrix[4][4] = {{0,1,0,1},{1,0,1,1},{0,1,0,1},{1,0,1,0}};




// edge list

vector<pair<int,int>> edges;

edges.push_back({1,2});

edges.push_back({2,3});

edges.push_back({2,4});

edges.push_back({3,4});

edges.push_back({4,1});

// for weighted graphs

vector<tuple<int,int,int>> weighted_edges;

weighted_edges.push_back({1,2,5});

weighted_edges.push_back({2,3,7});

weighted_edges.push_back({2,4,6});

weighted_edges.push_back({3,4,5});

weighted_edges.push_back({4,1,2});



// for undirected edge the pair is unordered

cout<<"build done successfully"<<endl;

return 0;
}

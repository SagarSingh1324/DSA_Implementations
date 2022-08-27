/*
 * =====================================================================================
 *
 *       Filename:  Bellman_Ford.cpp
 *
 *    Description: cpp implementation of Bellman Ford algorithm 
 *
 *        Version:  1.0
 *        Created:  27/08/22 11:58:13 AM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  SAGAR, 
 *   Organization:  NULL
 *
 * =====================================================================================
 */

#include<iostream>
#include<bits/stdc++.h>

int const inf=50;        // intial distance

using namespace std;

// definition of graph as edge list

vector<tuple<int,int,int>> edge;

int dist[7];

// function to calulate distances


void bell_ford(int ind)
{

dist[ind]=0;

for(int k=0; k<7;k++)
{
	for(auto const& ed:edge)
	{
		if((dist[get<0>(ed)]+get<2>(ed))<dist[get<1>(ed)])
		dist[get<1>(ed)]=dist[get<0>(ed)]+get<2>(ed);

	
	}

	for(auto const& ed2:edge)
	{
		if((dist[get<1>(ed2)]+get<2>(ed2))<dist[get<0>(ed2)])
		dist[get<0>(ed2)]=dist[get<1>(ed2)]+get<2>(ed2);
	}

}
}





int main()
{

for(int u=0; u<7; u++)
dist[u]=inf;

// defining the edge list representation of graph

edge.push_back({1,2,5});

edge.push_back({1,4,7});

edge.push_back({1,3,3});

edge.push_back({2,5,2});

edge.push_back({3,4,1});

edge.push_back({2,4,3});

edge.push_back({4,5,2});



// fuction call

bell_ford(4);

cout<<"build successful"<<endl;

return 0;
}

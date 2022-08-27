/*
 * =====================================================================================
 *
 *       Filename:  Dijkstra.cpp
 *
 *    Description: Implementation of Dijkstra Algorithm in C++ 
 *
 *        Version:  1.0
 *        Created:  27/08/22 02:06:44 PM IST
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

using namespace std;

int const inf=50;

//

vector<tuple<int,int,int>> edge; 

int dist[6];


// function definition

void dij(int ind)
{

dist[ind]=0;

int is_visited[7]={0};

//is_visited[ind]=1;

for(int k=1; k<6; k++)
{

// this finding of minimum node that has not been processed is
// done faster using prioroty queue data structure


	int min = inf;
	for(int i=1; i<6; i++)
	{	
		if((dist[i]<min)&&(!is_visited[i]))
		min=i;
	}



	for(auto itr: edge)
	{
		if(get<0>(itr)==min)
		{
			if((dist[get<0>(itr)]+get<2>(itr))<dist[get<1>(itr)])
			dist[get<1>(itr)]=(dist[get<0>(itr)]+get<2>(itr));
		}
	}

	is_visited[min]=1;
}
}




int main()
{

// intializing distance array

for(int i =0; i<6; i++)
{
	dist[i]=inf;
}

// graph defintion as edge list

edge.push_back({3,4,6});

edge.push_back({4,3,6});

edge.push_back({4,5,2});

edge.push_back({5,4,2});

edge.push_back({3,2,2});

edge.push_back({2,3,2});

edge.push_back({4,1,9});

edge.push_back({1,4,9});

edge.push_back({1,2,5});

edge.push_back({2,1,5});

edge.push_back({1,5,1});

edge.push_back({5,1,1});

// function call

dij(2);


cout<<"build successful"<<endl;


return 0;
}




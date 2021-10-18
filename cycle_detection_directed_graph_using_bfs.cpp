#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

bool isCycle(int n, vector<int> adj[]){
	vector<int> degree(n, 0);
	queue<int> q;

	for(int i=0; i<n; i++){
		for(auto it : adj[i])
			degree[it]++;
	}

	for(int i=0; i<n; i++){
		if(degree[i] == 0)
			q.push(i);
	}
	debug(degree);
	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;

		for(auto it : adj[node]){
			degree[it]--;
			if(degree[it] == 0)
				q.push(it);
		}
	}

	if(cnt == n)
		return false;
	return true;
}

int main(){
	freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	int n,m;
    // cout<<"Enter no. of Node : ";
    cin>>n;
    // cout<<"Enter no. of edge : ";
    cin>>m;

    // declare the adjacent list
    vector<int> adj[n+1];

    // cout<<"Enter u and v\n";
    // take edge as input
    for(int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    // for(int i=0; i<n; i++){
    // 	cout<<i<<": ";
    // 	for(auto x : adj[i])
    // 		cout<<x<<" ";
    // 	cout<<endl;
    // }

    cout<<isCycle(n, adj);
}
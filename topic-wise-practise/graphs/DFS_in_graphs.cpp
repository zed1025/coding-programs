/**
Problem Link: https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462
Date: 2023-03-11 11:51:58
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, list<int> > &adj ) {
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


void dfs(int node, 
unordered_map<int, bool> &visited, 
unordered_map<int, list<int> > &adj, vector<int> &component) {
    component.push_back(node);
    visited[node] = 1;

    //for every connected node make a recursive call
    for(auto i: adj[node]) {
        if(!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int> > adj;
    //prepare adjancency list
    prepareAdjList(edges, adj);

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    
    return 0;
}
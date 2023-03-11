/**
Problem Link: https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002
Date: 2023-03-11 11:38:28
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void prepareAdjList(unordered_map<int, set<int> > &adj, vector<pair<int, int>> &edges) {
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second ;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int> > &adj, 
unordered_map<int, bool> &visited, 
vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        //store front node in ans
        ans.push_back(frontNode);
        //push neighbours of front node into the queue
        for(auto i: adj[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    //only edges given so we have to make the adj list
    unordered_map<int, set<int> > adj; //change set to list if ordering is not nexessary
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adj, edges);

    //traverse all components
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}

int main() {
    
    return 0;
}
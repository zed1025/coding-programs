/**
Problem Link: 
Date: 2023-03-11 10:20:45
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


template <typename T>
class graph{
public:
    unordered_map<T, list<T> > adj;

    void addEdge(T u, T v, bool directed) {
        /**
         * directed == true => directed graph
         * directed == false => undirected graph
        */

        //create an edge from u to v
        adj[u].push_back(v);
        if(!directed) {
            adj[v].push_back(u);
        }
    } 

    void printAdjList() {
        for(auto i: adj) {
            cout << i.first  << "-> ";
            for(auto j: i.second) {
                cout << j << ", ";
            }cout << endl; 
        }
    }
};

int main() {
    int n, m, u, v;
    cout << "Enter the no of nodes: ";
    cin >> n;

    cout << "Enter the no of edges: ";
    cin >> m;

    graph<int> g;

    //creating a graph
    cout << "Enter edges: \n";
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        g.addEdge(u, v, false);
    }

    //printing a graph
    g.printAdjList();
    return 0;
}
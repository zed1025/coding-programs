/**
Problem Link: https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030
Date: 2023-03-10 10:02:34
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


//Approach 1
bool isSafe(int newx, int newy, vector<vector<bool> >&visited, vector<vector<int> > &arr, int n) {
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0) && arr[newx][newy] == 1) {
        return true;
    }
    return false;
}
void solve(int x, int y, 
    vector < vector < int >> & arr, int n, 
    vector<string> &ans, 
    vector<vector<bool> > &visited,
    string path) {

    //base case
    if(x==n-1 && y==n-1) { //destination reached
        ans.push_back(path);
        return ;
    }

    //4 movements
    //D
    if(isSafe(x+1, y, visited, arr, n)) {
        visited[x][y] = true;
        solve(x+1, y, arr, n, ans, visited, path+'D');
        visited[x][y] = false; //backtracking
    }
    //L
    if(isSafe(x, y-1, visited, arr, n)) {
        visited[x][y] = true;
        solve(x, y-1, arr, n, ans, visited, path+'L');
        visited[x][y] = false; //backtracking
    }
    //R
    if(isSafe(x, y+1, visited, arr, n)) {
        visited[x][y] = true;
        solve(x, y+1, arr, n, ans, visited, path+'R');
        visited[x][y] = false; //backtracking
    }
    //U
    if(isSafe(x-1, y, visited, arr, n)) {
        visited[x][y] = true;
        solve(x-1, y, arr, n, ans, visited, path+'U');
        visited[x][y] = false; //backtracking
    }
}



//Approach 2, slight modification
void solve2(int x, int y, 
    vector < vector < int >> & arr, int n, 
    vector<string> &ans, 
    vector<vector<bool> > &visited,
    string path) {

    //base case
    if(x==n-1 && y==n-1) { //destination reached
        ans.push_back(path);
        return ;
    }

    visited[x][y] = true;
    //4 movements
    //D
    if(isSafe(x+1, y, visited, arr, n)) {
        solve(x+1, y, arr, n, ans, visited, path+'D');
    }
    //L
    if(isSafe(x, y-1, visited, arr, n)) {
        solve(x, y-1, arr, n, ans, visited, path+'L');
    }
    //R
    if(isSafe(x, y+1, visited, arr, n)) {
        solve(x, y+1, arr, n, ans, visited, path+'R');
    }
    //U
    if(isSafe(x-1, y, visited, arr, n)) {
        solve(x-1, y, arr, n, ans, visited, path+'U');
    }
    visited[x][y] = false; //backtracking
}









vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool> > visited(n, vector<bool> (n, 0));
    string path = "";

    
    if(arr[0][0] == 0) { //if the starting position is 0
    
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);

    return ans;
}




int main() {
    
    return 0;
}
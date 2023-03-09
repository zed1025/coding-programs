/**
    Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
    Date: 18/01/2023 18:55:33
    Level: Medium
    Notes:
        - https://youtu.be/GqtyVD-x_jY
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &m) {
        if((x >= 0 && x < n) && (y >=0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path) {
        //base case
        if(x==n-1 && y==n-1) {
            ans.push_back(path);
            return;
        }
        
        //at this point you have reached x, y
        visited[x][y] = 1;
        
        // 4 choices -> D, U, L, R
        //down
        int newx = x+1, newy = y;
        if(isSafe(newx, newy, n, visited, m)) { //check if newx,newy is safe
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        //left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, n, visited, m)) { //check if newx,newy is safe
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, n, visited, m)) { //check if newx,newy is safe
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        //Up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, n, visited, m)) { //check if newx,newy is safe
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        
        visited[x][y] = 0; //for backtracking
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0) return ans;
        vector<vector<int>> visited = m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
        int srcx=0, srcy=0;
        string path = "";
        solve(m, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    
    return 0;
}
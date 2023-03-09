#include<bits/stdc++.h>
using namespace std;

bool isCompatible(vector<int> &board, int n, int k, int mid) {
    n = n+1;
    int sum = 0;
    int boardsCount = 1;
    
    for(int i=0; i<n; i++) {
        if(board[i]+sum <= mid) {
            sum = sum + board[i];
        } else {
            boardsCount++;
            if(boardsCount > k || board[i]>mid) {
                return false;
            }
            sum = board[i];
        }
    }
    return true;
}

int solution(vector<int> &boards, int k) {
    int s = 0;
    int e = 0;
    int n = boards.size()-1;
    for(int i=0; i<=n; i++) {
        e+=boards[i];
    }
    
    int mid = s + (e-s)/2;
    
    int ans = -1;
    
    while(s<=e) {
        cout << "Mid = " << mid << endl;
        if(isCompatible(boards, n, k, mid)) {
            ans = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {

    vector<int> boards = {1,2,3,4};
    int k=2;
    cout << solution(boards, k);

    return 0;
}
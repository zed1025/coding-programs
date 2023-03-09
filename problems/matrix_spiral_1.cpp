#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(const vector<vector<int> > &A) {
    int rows = A.size();
    int cols = A[0].size();
    int T=0, B=rows-1, L=0, R=cols-1;
    int count=0;
    int elements = rows*cols;
    int dir=0;
  	vector<int> res;
  	if(rows==1 && cols==1){
  		res.push_back(A[0][0]);
  		return res;
  	}
  	cout << T << " " << B << " " << L << " " << R << endl;
    while(count < elements) {
        if (dir==0) {
            for(int i=L; i<=R; i++) {
                res.push_back(A[T][i]);
                count++;
            }
            T++;
            dir=(dir+1)%4;
            continue;
        }
        if (dir==1) {
            for(int i=T; i<=B; i++) {
                res.push_back(A[i][R]);
                count++;
            }
            R--;
            dir=(dir+1)%4;
            continue;
        }
        if (dir==2) {
            for(int i=R; i>=L; i--) {
                res.push_back(A[B][i]);
                count++;
            }
            B--;
            dir=(dir+1)%4;
            continue;
        }
        if (dir==3) {
            for(int i=B; i>=T; i--) {
                res.push_back(A[i][L]);
                count++;
            }
            L++;
            dir=(dir+1)%4;
            continue;
        }
    }
    return res;
}
int main() {
	// vector<vector<int>> n = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	// vector<vector<int>> n = {{1}};
	// vector<vector<int>> n = {{1}, {2}, {3}};
    vector<vector<int>> n = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	vector<int> res = spiralOrder(n);
	for(auto x: res){
		cout << x << " ";
	}
}
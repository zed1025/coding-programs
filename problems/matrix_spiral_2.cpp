#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<vector<int>> v) {
	int rows=v.size(), cols=v[0].size();
	int t=0,b=rows-1,l=0,r=cols-1;
	int count=0;
	int elements = rows*cols;
	vector<int> sol;
	if(rows==1 && cols==1) {
		sol.push_back(v[0][0]);
		return sol;
	}
	int dir=0;
	while(count < elements){
		switch(dir) {
			case 0: //left
				for(int i=r; i>=l; i--) {
					count++;
					sol.push_back(v[t][i]);
				}
				t++;
				dir=(dir+1)%4;
				continue;
			case 1: //bottom
				for(int i=t; i<=b; i++) {
					count++;
					sol.push_back(v[i][l]);
				}
				l++;
				dir=(dir+1)%4;
				continue;
			case 2: //right
				for(int i=l; i<=r; i++) {
					count++;
					sol.push_back(v[b][i]);
				}
				b--;
				dir=(dir+1)%4;
				continue;
			case 3: //top
				for(int i=b; i>=t; i--) {
					count++;
					sol.push_back(v[i][r]);
				}
				r--;
				dir=(dir+1)%4;
				continue;
			default:
				continue;
		}
	}
	return sol;
}
int main() {
	vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<int> sol = solution(v);
	for(auto i: sol) {
		cout << i << " ";
	}
	cout << endl;
}
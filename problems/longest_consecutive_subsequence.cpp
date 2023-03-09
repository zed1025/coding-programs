#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	int findLongestConseqSubseq(int arr[], int N) {
		sort(arr, arr+N);
		for(int i=0; i<N; i++) {
			cout << arr[i] << " ";
		}cout << endl;
		int max_len=0;
		int len=0;
		for(int i=0; i<N; i++) {
			if(arr[i+1]-1 == arr[i]) {
				len += 1;
			} else if(arr[i+1] == arr[i]) {
				continue;
			} else {
				max_len = max(max_len, len+1);
				len=0;
			}
		}		

		return max_len;
	}

	// optimal solution, O(n) time and O(n) space
	int findLongestConseqSubseq_optim(int arr[], int N) {
		set<int> s; //O(n) space
		for(int i=0; i< N; i++) {
			s.insert(arr[i]);
		}
		map<int, int> m;
		int i=0;
		for(auto it=s.begin(); it!=s.end(); it++) {
			m.insert(make_pair(i++, *it));
		}
		int len=0, max_len=0;
		i=0;
		for(auto it=m.begin(); it!=m.end(); it++) {
			auto it2=m.find(i+1);
			if(it->second+1 == it2->second) {
				len++;
			} else {
				max_len = max(max_len, len+1);
				len=0;
			}
			i++;
		}
		return max_len;
	}

	// optimal solution, O(n) time and O(n) space, editorial
	int findLongestConseqSubseq_optim2(int nums[], int N) {
		priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<N;i++) {
            pq.push(nums[i]);
        }
        int prev=pq.top();
        pq.pop();
        int count=1, max_cnt=1;
        while(!pq.empty()) {
            if(pq.top()-prev > 1) {
                count=1;
                prev=pq.top();
                pq.pop();
            } else if(pq.top()-prev==0) {
                prev=pq.top();
                pq.pop();
            } else {
                count++;
                prev=pq.top();
                pq.pop();
            }
            max_cnt = max(max_cnt, count);
        }
        return max_cnt;
	}
};

int main() {
	int arr[] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
	int N=20;
	Solution ob;
	// cout << ob.findLongestConseqSubseq(arr, N);
	// cout << ob.findLongestConseqSubseq_optim(arr, N);
	cout << ob.findLongestConseqSubseq_optim2(arr, N);
}
/**
    Problem Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/
    Date: 14/01/2023 00:19:40
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// iterative solution -> AC
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        if(head == NULL) {
            return NULL;
        }
        while(head != NULL && head->next != NULL) {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            head = head->next->next;
        }
        return ans;
    }
};

//recursive solution -> AC
class Solution {
public:
    void solve(ListNode* head) {
        if(head == NULL) {
            return ;
        }
        if(head != NULL && head->next != NULL) {
            int temp = head->val;
            head->val = head->next->val;
            head->next->val = temp;
            //head = head->next->next;
            swapPairs(head->next->next);
        } else {
            return ;
        }
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = head;
        solve(head);
        return ans;
    }
};

int main() {
    
    return 0;
}
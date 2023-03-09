/**
    Problem Link:https://leetcode.com/problems/add-two-numbers/submissions/877579213/
    Date: 13/01/2023 23:27:19
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
public:
    void solve(ListNode* l1, ListNode *l2, ListNode* ans, int carry) {
        if(l1!=NULL || l2!=NULL || carry) {
            int sum=0;
            if(l1!=NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL) {
                sum+=l2->val;
                l2 = l2->next;
            }
            sum += carry;
            ListNode* n = new ListNode(sum%10);
            carry = sum/10;
            ans->next = n;
            ans = ans->next;
            solve(l1, l2, ans, carry);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        solve(l1, l2, ans, 0); //initial carry is zero

        return ans->next;
    }
};

//functions

int main() {
    
    return 0;
}
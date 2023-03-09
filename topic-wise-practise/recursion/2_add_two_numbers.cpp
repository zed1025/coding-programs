/**
    Problem Link: https://leetcode.com/problems/add-two-numbers/
    Date: 13/01/2023 12:29:00
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(); //empty node at the front
        ListNode* temp = ans;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry) {
            int sum=0;
            if(l1!=NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* n = new ListNode(sum%10);
            temp -> next = n;
            temp = temp->next;
        }
        return ans->next; 
    }
};

//functions

int main() {
    
    return 0;
}

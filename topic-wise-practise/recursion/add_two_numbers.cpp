/**
    Problem Link:
    Date: 13/01/2023 22:47:27
    Level: 
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
//solution 1 -> https://leetcode.com/problems/add-two-numbers/solutions/2759116/c-easy-to-understand/
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
        return ans->next; //because there is empty node at the front
    }
};

int main() {
    
    return 0;
}
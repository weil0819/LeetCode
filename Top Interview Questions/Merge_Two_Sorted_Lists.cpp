/*
Merge Two Sorted Lists
https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/771/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Scan l1 and l2 
    // Define a result list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode* pHead = NULL;         // static node
        
        // the head node
        if(l1->val <= l2->val) {
            pHead = l1;
            l1 = l1->next;
        }
        else {
            pHead = l2;
            l2 = l2->next;
        }
        
        ListNode* p = pHead;         // dynamic node 
        
        // scanning
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if(l1) p->next = l1;
        if(l2) p->next = l2;
        
        return pHead;
    }
};


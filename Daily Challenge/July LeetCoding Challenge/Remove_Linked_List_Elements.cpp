/*
Remove Linked List Elements

@date: July 20, 2020

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    // Three pointers: prev, cur, next 
    /*
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* cur = p;
        while(cur) {
            if(cur->next && cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return p->next;
    }
    */
    
    // Recursive
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        // head->next maybe itself or his next node
        head->next = removeElements(head->next, val);   
        return head->val == val ? head->next : head;
    }
};

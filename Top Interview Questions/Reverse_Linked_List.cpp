/*
Reverse Linked List
https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/560/

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

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
    // Method-II: recursively
    // consider from the last one to the first
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        // Until node =last node, and head = node before last
        ListNode* node = reverseList(head->next);
        
        // reverse last and its previous one
        head->next->next = head;
        head->next = NULL;
        
        return node;
    }
};


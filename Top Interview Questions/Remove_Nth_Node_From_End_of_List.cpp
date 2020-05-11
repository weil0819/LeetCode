/*
Remove Nth Node From End of List
https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/603/

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

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
    // Two pointers: "slow" and "fast"
    // when fast arrives end, slow will be n position
    // So let "fast" moves n steps first
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* slow = new_head;
        ListNode* fast = new_head;
        
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;            
        }
        
        // remove slow through replace slow with slow->next
        slow->next = slow->next->next;
        
        return new_head->next;
    }
};

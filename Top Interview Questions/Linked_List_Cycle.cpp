/*
Linked List Cycle
https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/773/

@date: May 11, 2020

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 

Follow up:

Can you solve it using O(1) (i.e. constant) memory?

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
    // Two pointers: slow and fast
    // The slow pointer moves one step at a time while the fast pointer moves two steps at a time.
    // if a cycle exists, fast will meet slow
    bool hasCycle(ListNode *head) {
        // only one node is not a cycle
        if(head == NULL || head->next == NULL) return false; 
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // make sure fast can move two steps
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        // fast reach the end, no cycle
        return false;
    }
};



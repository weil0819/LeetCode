/*
Palindrome Linked List
https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/772/

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

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
    // slow moves 1 step and fast moves 2 steps
    // for odd, fast is last; for even, fast is NULL
    // reverse from slow+1
    bool isPalindrome(ListNode* head) {
        // if only 0 or 1 node in the list
        if(head == NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        
        // scan and compare two lists
        while(slow->next) {
            if(head->val != slow->next->val) return false;
            else {
                head = head->next;
                slow->next = slow->next->next;
            }
        }
        return true;
    }
    
private:
    ListNode* reverse(ListNode* node) {
        ListNode* pre = NULL;
        ListNode* cur = node;
        while(cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

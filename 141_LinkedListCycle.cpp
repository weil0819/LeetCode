//===========================================================================================
// 141. Linked List Cycle
// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?
//===========================================================================================


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
    /**
    * Idea: we use two points in which one is slow point and another is fast point
    * slow is one step at a time, and fast is two steps at a time
    * 
    */
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
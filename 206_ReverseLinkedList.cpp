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
    * Idea: 1.recursive solution 
    * eg, 1---------->2---------->3---------->4
    *     head => head->next
    * we want 2---------->1, so 
    *                           head->next->next = head; // 2'next points to 1
    *                           head->next = NULL;       // 1'next points to NULL
    * Start from 4---------->3, so
    *                           head->next->next = head; // 4'next points to 3
    *                           head->next = NULL;       // 3'next points to NULL 
    */
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        // conduct recursion until head points to last-but-one ListNode, and head->next points to tail ListNode
        ListNode* node = reverseList(head->next); 
        head->next->next = head;
        head->next = NULL;   
        return node;
    }
};
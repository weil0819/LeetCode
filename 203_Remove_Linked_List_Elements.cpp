//===========================================================================================
// 203. Remove Linked List Elements
// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    * Idea: removing a LinkedList Node is equal to replace the current node with the next node
    * Attention: If the last node's val is val, we should delete it directly
    * Thus, we should create a pseudo head and always consider the next node not current node
    * 
    */
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* cur = p;              //moving point
        while(cur){
            if(cur->next && cur->next->val == val){ //cur--->(cur->next)--->cur->next->next
                cur->next = cur->next->next;        //remove cur->next node
            }else{
                cur = cur->next;
            }
        }
        return p->next;
    }
};
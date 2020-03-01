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
    * Idea: For a linked-list, we delete one node by replace the next node with current node
    * that is, node->val = node->next->val; node->next = node->next->next;  
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while(node){
            while(node->next && node->next->val == node->val){
                node->val = node->next->val;
                node->next = node->next->next;
            }
            node = node->next;            
        }
        return head;
    }
};
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
    * Idea: 1->3->5->7 and 2->4->6->8
    * We should compare the head of the two linked-list
    * We can adopt the recursion or non-recursion methods
    * set two points one moves forward while another keep static
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        ListNode* pHead = NULL;
        if(l1->val <= l2->val){
            pHead = l1;
            l1 = l1->next;
        }else{
            pHead = l2;
            l2 = l2->next;
        }  
        ListNode* p = pHead;        // p dynamic, pHead static
        
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 != NULL){
            p->next = l1;
        }else if(l2 != NULL){
            p->next = l2;
        }
        
        return pHead;
        
    }
};
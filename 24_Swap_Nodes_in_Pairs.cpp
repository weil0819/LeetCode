//===========================================================================================
// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. 
// You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL){
    		return NULL;
    	}
    	if(head->next == NULL){
    		return head;
    	}
        ListNode* cur = head;			// 1->2->3, cur=1
        ListNode* tmp = cur->next;		// tmp=2
        cur->next = tmp->next;			// tmp->next=3, 1->3
        tmp->next = cur;				// 2->1->3, cur=1
        ListNode* pHead = tmp;
        while(cur->next && cur->next->next){	//cur=1, cur->next=3, cur->next->next=4
        	ListNode* fir = cur->next;			//fir=3
        	ListNode* sec = cur->next->next;	//sec=4
        	//swap
        	cur->next = sec;					//1->4
        	fir->next = sec->next;				//3->5
			sec->next = fir;					//4->3
			cur = cur->next->next;				//1->4->3, so cur=3
        }

        return pHead;
    }
};


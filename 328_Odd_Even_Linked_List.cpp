//===========================================================================================
// 328. Odd Even Linked List

// Given a singly linked list, group all odd nodes together followed by the even nodes. 
// Please note here we are talking about the node number and not the value in the nodes.

// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.

// Note:
// The relative order inside both the even and odd groups should remain as it was in the input. 
// The first node is considered odd, the second node even and so on ...
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
	* Idea: we consider using two points which point to odd and even positions
	* Initially, odd points to head, and even points to head->next
	* Finally, we joint two list: odd-<next = evenHead (Here, evenHead points to the first node in even list)
	*
	*/
    ListNode* oddEvenList(ListNode* head) {
    	if(head == NULL){
    		return NULL;
    	}
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while(even && even->next){				// if even is not NULL, odd and odd->next must be not NULL
        	odd->next = odd->next->next;
        	even->next = even->next->next;
        	odd = odd->next;
        	even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
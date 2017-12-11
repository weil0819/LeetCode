//===========================================================================================
// 160. Intersection of Two Linked Lists
// Write a program to find the node at which the intersection of two singly linked lists begins.


// For example, the following two linked lists:

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
// begin to intersect at node c1.


// Notes:

// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
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
private:
    ListNode *check(ListNode *p, ListNode *q){	// traverse A to compare the certain ListNode q
    	while(p && p != q){
    		p = p->next;
    		if(p == q){
    			return q;
    		}
    	}
    	return NULL;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;

        if(!headA || !headB){
        	return NULL;
        }

        while(q){								// traverse B to compare A with the certain ListNode B
        	ListNode* pp = p;
        	ListNode *tmp = check(pp, q);
        	if(tmp != NULL){
        		return tmp;
        	}else{
        		q = q->next;
        	}
        }

        return NULL;
    }

};

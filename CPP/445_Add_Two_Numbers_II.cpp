//===========================================================================================
// 445. Add Two Numbers II

// You are given two non-empty linked lists representing two non-negative integers. 
// The most significant digit comes first and each of their nodes contain a single digit. 
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7
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
	* Idea: we can use two stacks to record the integers of l1 and l2
	* and then store the sum in the third stack
	* 
	*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL){
    		return l2;
    	}
    	if(l2 == NULL){
    		return l1;
    	}
        stack<int> s1;
        stack<int> s2;
        stack<int> s3;
        while(l1){
        	s1.push(l1->val);
        	l1 = l1->next;
        }
        while(l2){
        	s2.push(l2->val);
        	l2 = l2->next;
        }
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry != 0){
        	int t1 = 0, t2 = 0;
            if(!s1.empty()){
                t1 = s1.top();
                s1.pop();
            }
        	if(!s2.empty()){
                t2 = s2.top();
                s2.pop();
            }       	
            int sum = (carry+t1+t2)%10;
        	carry = carry + t1 + t2 >= 10 ? 1 : 0;            
        	s3.push(sum);
        }
        ListNode* p = new ListNode(-1);
        ListNode* q = p;
        while(!s3.empty()){
        	q->next = new ListNode(s3.top());
        	s3.pop();
        	q = q->next;
        }
        return p->next;
    }
};
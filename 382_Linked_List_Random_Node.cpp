//===========================================================================================
// 382. Linked List Random Node

// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Follow up:
// What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

// Example:

// // Init a singly linked list [1,2,3].
// ListNode head = new ListNode(1);
// head.next = new ListNode(2);
// head.next.next = new ListNode(3);
// Solution solution = new Solution(head);

// // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
// solution.getRandom();
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
	ListNode* head;
public:
	/**
	* Idea: This is a Reservoir sampling problem, which can refer http://blog.jobbole.com/42550/
	* In a streaming, the probability of choosing the cnt-th element is 1/cnt
	* the probability of choosing the (cnt+1)-th element is 1/(cnt+1)
	*
	*/
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = head->next;
        int res = head->val;
        int cnt = 2;
        while(node){
        	int tmp = rand()%cnt;		// generate an integer between 0 and cnt-1
        	if(tmp == 0){				// the probability of tmp = 0 is 1/cnt
        		res = node->val;		// replace elements with gradually decreasing probability
        	}
        	cnt++;
        	node = node->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
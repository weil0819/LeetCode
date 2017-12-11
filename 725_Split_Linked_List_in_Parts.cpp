//===========================================================================================
// 725. Split Linked List in Parts

// Given a (singly) linked list with head node root, 
// write a function to split the linked list into k consecutive linked list "parts".

// The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. 
// This may lead to some parts being null.

// The parts should be in order of occurrence in the input list, 
// and parts occurring earlier should always have a size greater than or equal parts occurring later.

// Return a List of ListNode's representing the linked list parts that are formed.

// Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
// Example 1:
// Input: 
// root = [1, 2, 3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The input and each element of the output are ListNodes, not arrays.
// For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but it's string representation as a ListNode is [].
// Example 2:
// Input: 
// root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
// Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, 
// and earlier parts are a larger size than the later parts.
// Note:

// The length of root will be in the range [0, 1000].
// Each value of a node in the input will be an integer in the range [0, 999].
// k will be an integer in the range [1, 50].
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
	* Idea: We should count the number of node in List, and then divide it into k parts
	* If n <= k, each node will be a List and the remaining parts will be NULL
	* If n > k, n/k will be basic length of List, and the former n%k Lists will be (n/k+1)
	* 
	*/
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, NULL);
        if(root == NULL){
        	return res;
        }
        int n = 0;
       	ListNode* p = root;
       	while(p){
       		++n;
       		p = p->next;
       	}
       	int len = n/k, remain = n%k;
       	ListNode* node = root;		// node is the head node of each part
        ListNode* prev = NULL;		// prev is the tail node of each part, and its next must be NULL
       	for(int i = 0; i < k; i++){
       		res[i] = node;
       		int tmp = remain > 0 ? len+1 : len;
       		--remain;
       		for(int j = 0; j < tmp; j++){
       			prev = node;
       			node = node->next;
       		}
       		if(prev){				// end each part
       			prev->next = NULL;
       		}
       	}
        return res;
    }
};



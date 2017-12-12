//===========================================================================================
// 390. Elimination Game

// There is a list of sorted integers from 1 to n. Starting from left to right, 
// remove the first number and every other number afterward until you reach the end of the list.

// Repeat the previous step again, but this time from right to left, 
// remove the right most number and every other number from the remaining numbers.

// We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

// Find the last number that remains starting with a list of length n.

// Example:

// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6

// Output:
// 6
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a recursion problem
	* when starting from left to right, we need to move head
	* when starting from right to left and remaining is odd, we need to move head
	* In first round, we jump one step each time; in second round, we jump two steps each time; in third round, we jump 4 steps
	* In each round, the remaining is always half of former
	*
	*/
    int lastRemaining(int n) {
        bool left = true;
        int remaining = n, step = 1, head = 1;
        while(remaining > 1){
        	if(left || remaining%2==1){
        		head = head + step;
        	}
        	remaining = remaining/2;
        	step = step * 2;
        	left = !left;
        }
        return head;
    }

};
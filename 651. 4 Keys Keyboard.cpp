/*
651. 4 Keys Keyboard -- Medium
https://www.leetfree.com/problems/4-keys-keyboard.html

Imagine you have a special keyboard with the following keys:

Key 1: (A): Print one 'A' on screen.

Key 2: (Ctrl-A): Select the whole screen.

Key 3: (Ctrl-C): Copy selection to buffer.

Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.

Example 1:
Input: N = 3
Output: 3
Explanation: 
We can at most get 3 A's on screen by pressing following key sequence:
A, A, A

Example 2:
Input: N = 7
Output: 9
Explanation: 
We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

Note:
1 <= N <= 50
Answers will be in the range of 32-bit signed integer.

*/

class Solution {
public:
	int maxA(int N){
		if(N <= 6) return N;
		int max = 0;
		for(int j = N-3; j >= 1; j--){
			int cur = (N-j-1)*maxA(j);;
			if(cur > max){
				max = cur;
			}
		}
		return max;
	}

};
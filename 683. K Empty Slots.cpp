/*
683. K Empty Slots -- Hard
http://www.leetfree.com/problems/k-empty-slots.html

There is a garden with N slots. In each slot, there is a flower. 
The N flowers will bloom one by one in N days. 
In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. 
Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, 
where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, 
and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:

Input: 
flowers: [1,3,2]
k: 1

Output: 2
Explanation: In the second day, the first and the third flower have become blooming.

Example 2:

Input: 
flowers: [1,2,3]
k: 1

Output: -1

Note:
The given array will be in the range [1, 20000].

*/

class Solution {
public:
	/*
	flowers[i] = x表示第i天的时候，第x个花槽开花

	使用数组day记录1~N个花槽是第几天开花，即day[i] = x 表示第i个花槽在第x天开花
	然后从头遍历，查看每隔k天的两个花槽left和right之间是否有比day[left]和day[right]更早开花的日子
	即，day[i] < day[left] 或 day[i] < day[right]
	如果有那么就移动left和right，并保持两者差k天
	*/
    int kEmptySlots(vector<int>& flowers, int k) {
    	int n = flowers.size();
    	if(n == 0) return -1;
    	vector<int> day(n);

    	for(int i = 0; i < n; i++){
    		day[flowers[i]-1] = i+1;
    	}

    	// scan
    	int ans = INT_MAX, left = 0, right = k+1;	// k flowers between left and right
    	while(right < n){
    		bool flag = false;
    		for(int i = left+1; i < right; i++){
    			if(day[i] < day[left] || day[i] < day[right]){	// the i-flower bloom between left and right
    				left = i;
    				right = i+k+1;					// right = left + k + 1
    				flag = true;
    				break;
    			}
    		}
    		if(flag) continue;
    		ans = min(ans, max(day[left], day[right]));
    		left = right;			// [left, right] is valid, and then continue moving
    		right = left + k + 1;
    	}
    	return ans < INT_MAX ? ans : -1;
    }
};
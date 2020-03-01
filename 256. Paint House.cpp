/*

256. Paint House -- Easy
https://www.leetfree.com/problems/paint-house.html

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red; 
costs[1][2] is the cost of painting house 1 with color green, 
and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

*/

/*
用red, blue, green三种颜色油漆房子(每种颜色的消耗值不同)，要求相邻房子不能同色
求最小消耗

每个房子有三种染色方案, 那么如果当前房子染红色的话, 最小代价将是上一个房子的绿色和蓝色的
最小代价+当前房子染红色的代价. 对另外两种颜色也是如此. 因此动态转移方程为: 

             red = min(prevBlue, prevGreen) + costs[i][0];	// 当前red

             blue = min(prevRed, prevGreen) + costs[i][1];	// 当前blue

             green = min(prevRed, prevBlue) + costs[i][2];	// 当前green

*/


class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    	int n = costs.size();
    	if(costs == NULL && n == 0) return 0;
    	int red = 0, blue = 0, green = 0;		// O(1) space complexity
    	for(int i = 0; i < n; i++){
    		int prevRed = red, prevBlue = blue, prevGreen = green;
    		red = costs[i][0] + min(prevBlue, prevGreen);
    		blue = costs[i][1] + min(prevRed, prevGreen);
    		green = costs[i][2] + min(prevRed, prevBlue);
    	}

    	return min(red, min(blue, green));
    }
};



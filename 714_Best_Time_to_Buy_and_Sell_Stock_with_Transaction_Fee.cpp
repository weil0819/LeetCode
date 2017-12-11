//===========================================================================================
// 714. Best Time to Buy and Sell Stock with Transaction Fee

// Your are given an array of integers prices, for which the i-th element is the price of 
// a given stock on day i; and a non-negative integer fee representing a transaction fee.

// You may complete as many transactions as you like, but you need to pay the transaction 
// fee for each transaction. You may not buy more than 1 share of a stock at a time 
// (ie. you must sell the stock share before you buy again.)

// Return the maximum profit you can make.

// Example 1:
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1
// Selling at prices[3] = 8
// Buying at prices[4] = 4
// Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Note:

// 0 < prices.length <= 50000.
// 0 < prices[i] < 50000.
// 0 <= fee < 50000.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is DP problem.
	* there are two states:
	* cash denotes the maximum profit we could have if we did not have a share of stock
	* hold denotes the maximum profit we could have if we owned a share of stock
	* 
	* for i-th day, we have three cases: 
	* 1) sell the stock
	* 2) buy the stack
	* 3) do nothing
	* In case1: we must hold the stock before i-th day, cash = max{cash, hold+prices[i]-fee}
	* In case2: hold = max{hold, cash-prices[i]}
	* In case3: change nothing
	*/

    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for(int i = 1; i < prices.size(); i++){
        	cash = max(cash, hold+prices[i]-fee);
        	hold = max(hold, cash-prices[i]);
        }
        return cash;
    }
};

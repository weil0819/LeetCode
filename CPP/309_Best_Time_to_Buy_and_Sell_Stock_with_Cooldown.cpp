//===========================================================================================
// 309. Best Time to Buy and Sell Stock with Cooldown

// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* this problem has 3 possible transactions: buy, sell and cooldown
	* For each of them we make an array, buy[n], sell[n] and cooldown[n].
	* buy[i] means before day i what is the maxProfit for any sequence end with buy.
	* sell[i] means before day i what is the maxProfit for any sequence end with sell.
	* cooldown[i] means before day i what is the maxProfit for any sequence end with cooldown.
	* We have 
	* buy[i]  = max(cooldown[i-1]-price, buy[i-1]) // case1: buy on day i; case2: cooldonw on day i
	* sell[i] = max(buy[i-1]+price, sell[i-1])	   // case1: sell on day i; case2: cooldown on day i
	* cooldown[i] = max(sell[i-1], buy[i-1], cooldown[i-1])// case1: buy on 
	* 
	*/
    int maxProfit(vector<int>& prices) {
    	int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    	for (int price : prices) {
        	prev_buy = buy;
        	buy = max(prev_sell - price, buy);
        	prev_sell = sell;
        	sell = max(prev_buy + price, sell);
    	}
    	return sell;        
    }
};


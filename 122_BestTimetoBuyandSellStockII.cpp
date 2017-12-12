class Solution {
public:
    /**
    * Idea: if the i+1 day's price is higher than the i day's price, add to sum
    */
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int profit = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i+1] - prices[i] > 0){
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};
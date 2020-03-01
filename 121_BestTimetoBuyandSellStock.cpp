class Solution {
public:
    /**
    * Idea: use two variables minPri and maxPro to record the minimum price and maximum profit
    * maxPro is the larger one between current maxPro and prices[i]-minPri
    */
    int maxProfit(vector<int>& prices) {
        int minPri = INT_MAX, maxPro = 0;
        for(int i = 0; i < prices.size(); i++){
            minPri = min(minPri, prices[i]);
            maxPro = max(maxPro, prices[i]-minPri);
        }
        return maxPro;
    }
};
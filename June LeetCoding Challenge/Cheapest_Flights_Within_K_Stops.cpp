/*
Cheapest Flights Within K Stops

@date: June 14, 2020

There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

*/

class Solution {
public:
    // DP
    // dp[i][j] = Dist to reach j using atmost i edges from src
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int> > dp(K+2, vector<int>(n, INT_MAX)); // dp[i][j] initialize as INT_MAX
        
        for(int i = 0; i <= K+1; i++) {
            dp[i][src] = 0;     // Dist to reach src always zero
        }
        
        for(int i = 1; i <= K+1; i++) {
            for(auto f: flights) {
                int u = f[0];     // src
                int v = f[1];     // dst
                int w = f[2];     // price
                
                // find min dist to reach v using i edges from src
                if(dp[i-1][u] != INT_MAX){
                    dp[i][v] = min(dp[i-1][u] + w, dp[i][v]);
                }                
            }
        }
        return (dp[K+1][dst] == INT_MAX) ? -1 : dp[K+1][dst];
    }
};


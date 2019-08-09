/*

332. Reconstruct Itinerary -- Easy 
https://leetcode.com/problems/reconstruct-itinerary/ 

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. 
All of the tickets belong to a man who departs from JFK. 
Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string> > graph;
        vector<string> res;
        
        if(tickets.size() == 0) return res;
        
        for(auto ticket: tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        stack<string> dfs;
        dfs.push("JFK");
        while(!dfs.empty()) {
            string tmp = dfs.top();
            // terminate search
            if(graph[tmp].empty()) {
                res.push_back(tmp);     // insert the last arrival--->the first departure
                dfs.pop();
            } else {
                // push the first element in arrival set of tmp
                multiset<string>::iterator it = graph[tmp].begin();
                dfs.push(*it);
                // remove *it from graph[tmp]
                graph[tmp].erase(it);
            }
        }
        
        // reverse the vector
        reverse(res.begin(),res.end());
        
        return res;
    }      
};



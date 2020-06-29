/*
Reconstruct Itinerary

@date: June 28, 2020

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
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
    // Graph + DFS + stack
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // store <from, list>
        unordered_map<string, multiset<string>> adjList;
        vector<string> res;     // result value
        int N = tickets.size();
        if(N == 0) return res;
        
        // generate adj list
        for(auto ticket: tickets) {
            adjList[ticket[0]].insert(ticket[1]);
        }
        
        // define stack
        stack<string> S;
        S.push("JFK");
        
        while(!S.empty()) {
            string temp = S.top();
            // arrive end, then pop out
            if(adjList[temp].empty()) {
                res.push_back(temp);
                S.pop();
            } else {
                multiset<string>::iterator iter = adjList[temp].begin();
                S.push(*iter);
                adjList[temp].erase(iter);
            }
        }
        
        return vector<string>(res.rbegin(), res.rend());        
    }
};

/*
Possible Bipartition

@date: May 27, 2020

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/


class Solution {
public:
    // Independent set
    // bipartite graph -- graph coloring
    // the first node is RED, while its neighbor should not be same color
    // finally, nodes in same color will be in one group
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> > adj(N+1);      // adjacency list
        vector<bool> visited(N+1, false);
        vector<int> color(N+1, 0);          // color in each node, default is 0, RED==-1, BLUE==1
        
        for(int i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        // BFS by using queue
        queue<int> Q;
        // Scan each node as starting point of BFS
        for(int i = 1; i<= N; i++) {
            if(visited[i]) continue;
            Q.push(i);            
            color[i] = -1;
            
            while(!Q.empty()) {
                int node = Q.front();
                Q.pop();
                if(visited[node]) continue;
                visited[node] = true;
                
                // Consider its neighbor
                for(int j = 0; j < adj[node].size(); j++) {
                    // compare their colors
                    if(color[node] == color[adj[node][j]]) return false;
                    
                    // assign opposite color to its neighbor
                    if(color[adj[node][j]] == 0) color[adj[node][j]] = -color[node];
                    Q.push(adj[node][j]);
                }
            }                        
        }
        
        return true;
    }
};


/*
Course Schedule

@date: May 29, 2020

There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5

*/

class Solution {
public:
    // whether there is a cycle in directed graph
    // Scan each node and use DFS to traverse directed graph
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Generate a directed graph via adjacency list.
        vector<vector<int> > adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        
        // Create a visit array to record graph node in each DFS traversal
        vector<bool> visited(numCourses, false);
        
        // Iterate each graph node and use DFS to traverse a path.
        for(int i = 0; i < numCourses; i++) {
            // Having a cycle
            if(!DFSUtil(i, visited, adj)) return false;
        }
        // No cycle for all nodes
        return true;
    }
private:
    bool DFSUtil(int course, vector<bool>& visited, vector<vector<int> >& adj) {
        // if visited, that means there is a cycle
        if(visited[course]) return false;
        
        // mark it as visited in this round DFS traversal
        visited[course] = true;
        
        // find next course through adjacency list
        for(int i = 0; i < adj[course].size(); i++) {
            int next = adj[course][i];
            // any cycle exists, return false
            if(!DFSUtil(next, visited, adj)) return false;
        }
        
        // recover entry point for next round
        visited[course] = false;
        return true;
    }
};



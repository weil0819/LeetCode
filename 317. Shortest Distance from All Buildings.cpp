/*

317. Shortest Distance from All Buildings -- Hard
http://www.leetfree.com/problems/shortest-distance-from-all-buildings.html

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

*/

/*
选一块空地建楼，使得它到其余楼的距离之和最小
*/
class Solution {  
public:  
	/*
	从一个建筑物出发来计算每一个空地到这个建筑物的距离, 
	然后设置一个数组sumDistance来累加统计从一个空地出发到其他所有建筑物的距离.
	即sumDistance[i][j]代表从位置grid[i][j]出发到其他建筑物的距离之和.

	其中在从一个建筑出发寻找所有空地到其距离的时候, 我们使用bfs来计算, 
	并且可以每次访问地图的一个结点之后将其值-1, 用作标记已经访问过此结点, 
	也用于标记下一次可访问这个结点.这样就避免了再开一个数组来标记是否访问过.
	*/
    int shortestDistance(vector<vector<int>>& grid) {  
        if(grid.size()==0) return 0;
        int m = grid.size(), n = grid[0].size(), ans, flag=0;
        vector<pair<int, int>> dir{{0,1}, {0,-1}, {1,0}, {-1, 0}};
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j =0; j < n; j++)
            {
                if(grid[i][j] != 1) continue;
                ans = INT_MAX;
                queue<pair<int, int>> que;
                que.push(make_pair(i*n+j, 0));
                while(!que.empty())
                {
                    auto val = que.front();
                    que.pop();
                    for(auto v: dir)
                    {
                        int x = val.first/n+v.first, y = val.first%n+v.second;
                        if(x<0||x>=m||y<0||y>=n||grid[x][y]!=flag) continue;
                        cnt[x][y] += val.second+1, grid[x][y]--;
                        ans = min(ans, cnt[x][y]);
                        que.push(make_pair(x*n+y, val.second+1));
                    } 
                }
                flag--;
            }
        }
        return ans==INT_MAX?-1:ans;
    }  
};  
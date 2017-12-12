class Solution {
public:
    /**
    * Idea: DFS/BFS is used to find each island and then compare with the current maximum one
    * traverse vertex in each row and column as start point to do BFS or DFS
    * use grid[i][j]=-1 to record the grid which has been visited
    */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxCur = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 || grid[i][j] == -1){
                    continue ;
                }
                int tmp = BFSUtil(grid, i, j);
                if(tmp > maxCur){
                    maxCur = tmp;
                }
            }
        }
        
        return maxCur;
    }
    
private:
    int BFSUtil(vector<vector<int> >& grid, int row, int col){        
        queue<pair<int, int> > q;
        q.push(make_pair(row, col));     
        int island = 1;
        grid[row][col] = -1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x-1 >= 0 && grid[x-1][y] == 1){
                ++island;
                q.push(make_pair(x-1, y));
                grid[x-1][y] = -1;
            }
            if(x+1 < grid.size() && grid[x+1][y] == 1){
                ++island;
                q.push(make_pair(x+1, y));
                grid[x+1][y] = -1;
            }
            if(y-1 >= 0 && grid[x][y-1] == 1){
                ++island;
                q.push(make_pair(x, y-1));
                grid[x][y-1] = -1;
            }
            if(y+1 < grid[0].size() && grid[x][y+1] == 1){
                ++island;
                q.push(make_pair(x, y+1));
                grid[x][y+1] = -1;
            }            
        }
        return island;
    }
    
    
};

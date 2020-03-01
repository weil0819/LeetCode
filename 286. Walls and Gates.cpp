/*

286. Walls and Gates -- Medium
http://www.leetfree.com/problems/walls-and-gates.html


You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF 
as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. 
If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF

After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/

/*
网格中三种状态：-1, 0, INF，分别表示墙，门，空
求空到最近的门的距离
*/
class Solution {  
private:
    void DFS(vector<vector<int>>& rooms, int x, int y, int distance) {
        int row = rooms.size(), col = rooms[0].size();
        if(x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] < distance) {
            return;
        }
        rooms[x][y] = distance++;
        DFS(rooms, x + 1, y, distance);		// consider the four directions of (x,y)
        DFS(rooms, x - 1, y, distance);		// compute the distance to (x,y) who is a gate
        DFS(rooms, x, y - 1, distance);
        DFS(rooms, x, y + 1, distance);
    }

public:       
	/*
	matrix问题：通常是DFS和BFS方法
	Method-I: DFS：深度优先搜索的代码更加简洁。
	对于每一个二维矩阵中的0元素，我们对其进行深度优先搜索。
	其思路是，如果当前格子的的距离大于等于新的距离，就更新当前格子的距离，
	并且对其四个邻接格子进行深度搜索。需要注意边界情况的控制。
	*/
    void wallsAndGates(vector<vector<int>>& rooms) {  
        if(rooms.size() == 0 || rooms[0].size() == 0) {
            return;
        }
        int row_num = rooms.size(), col_num = rooms[0].size();
        for(int i = 0; i < row_num; ++i) {
            for(int j = 0; j < col_num; ++j) {
                if(rooms[i][j] == 0) {
                    DFS(rooms, i, j, 0);
                }
            }
        } 
    }

    /*
    Method-II: BFS：广度优先搜索的思路更加直观。我们维护一个队列，
    用来表示需要处理的所有格子信息，包括格子的具体位置以及当前距离，
    队列初始化为二维矩阵中的所有0元素。然后依次对队列的头元素进行处理，
    直到队列为空。具体处理方法是：如果头结点的某个邻居结点的值为INF，则更新该值，
    并且将该邻接结点放入队列中。由于保证了队列中“当前距离”的单调递增性，所以我们只需要处理那些距离为INF的邻居结点。
    */  

    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size() == 0 || rooms[0].size() == 0) {
            return;
        }
        int row_num = rooms.size(), col_num = rooms[0].size();
        queue<pair<pair<int, int>, int>> q;		// <<x,y>, distance>
        for(int i = 0; i < row_num; ++i) {
            for(int j = 0; j < col_num; ++j) {
                if(rooms[i][j] == 0) {
                    q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }
        int INF = INT_MAX;
        while(!q.empty()) {
            int row = q.front().first.first, col = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            if(row > 0 && rooms[row - 1][col] == INF) {
                rooms[row - 1][col] = distance + 1;
                q.push(make_pair(make_pair(row - 1, col), distance + 1));
            }
            if(row < row_num - 1 && rooms[row + 1][col] == INF) {
                rooms[row + 1][col] = distance + 1;
                q.push(make_pair(make_pair(row + 1, col), distance + 1));
            }
            if(col > 0 && rooms[row][col - 1] == INF) {
                rooms[row][col - 1] = distance + 1;
                q.push(make_pair(make_pair(row, col - 1), distance + 1));
            }
            if(col < col_num - 1 && rooms[row][col + 1] == INF) {
                rooms[row][col + 1] = distance + 1;
                q.push(make_pair(make_pair(row, col + 1), distance + 1));
            }
        }
    }

};  


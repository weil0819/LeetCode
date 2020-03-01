/*
874. Walking Robot Simulation -- Easy
https://leetcode.com/problems/walking-robot-simulation/

@date: Sun 1 Mar. 2020

A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.

*/

class Solution {
public:
    // Just follow the rules and take care of obstacles
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int N = commands.size(), M = obstacles.size();
        set<pair<int,int> > help;
        for(auto obstacle: obstacles) {
            help.insert(make_pair(obstacle[0], obstacle[1]));
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0;   
        int direction = 0;  // up=0, down=1, left=2, right=3
        int res = 0;
        for(int i = 0; i < N; i++) {
            if(commands[i] == -2){
                direction = (direction + 3) % 4;
            }else if(commands[i]==-1) {
                direction = (direction + 1) % 4;
            }else {
                for(int j = 0; j < commands[i]; j++) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    if(help.find(make_pair(nx,ny)) == help.end()) {
                        x = nx;
                        y = ny;
                        res = max(res, x*x+y*y);
                    }
                }
            }
        }
        
        return res;
    }
};

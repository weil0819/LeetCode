/*
Check If It Is a Straight Line

@date: May 8, 2020

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 
Example 1:


Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:


Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/

class Solution {
public:
    // define a line by the first two points
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int N = coordinates.size();
        if(N < 2) return false;
        if(N == 2) return true;
        
        for(int i = 2; i < N; i++) {
            int x1 = coordinates[i-2][0], y1 = coordinates[i-2][1];
            int x2 = coordinates[i-1][0], y2 = coordinates[i-1][1];
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            if((y3-y2) * (x2-x1) != (y2-y1) * (x3-x2)) return false;                        
        }
        return true;
    }
};

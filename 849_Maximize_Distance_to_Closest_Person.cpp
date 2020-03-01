/*
849. Maximize Distance to Closest Person
https://leetcode.com/contest/weekly-contest-88/problems/maximize-distance-to-closest-person/

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.

*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        if(n == 0) return 0;
        int i = 0;          // i indicates the closet 1
        int ans = 0;        // return value
        for(int j = 0; j < n; j++){                 // O(n) and O(1)
            if(seats[j] == 1){                
                if(i == 0) ans = max(ans, j-i);     // prefix, 0001, i=0, j=3
                else{
                    ans = max(ans, (j-i+1)/2);      // middle, 10001, i=1, j=4
                }
                i = j+1;
            }
        }
        ans = max(ans, n-i);                        // suffix, 1000, i=1, n=4
        return ans;
    }
};

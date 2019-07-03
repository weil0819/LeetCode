//===========================================================================================
// 554. Brick Wall

// There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. 
// The bricks have the same height but different width. 
// You want to draw a vertical line from the top to the bottom and cross the least bricks.

// The brick wall is represented by a list of rows. 
// Each row is a list of integers representing the width of each brick 
// in this row from left to right.

// If your line go through the edge of a brick, then the brick is not considered as crossed. 
// You need to find out how to draw the line to cross the least bricks and 
// return the number of crossed bricks.

// You cannot draw a line just along one of the two vertical edges of the wall, 
// in which case the line will obviously cross no bricks.

// Example:
// Input: 
// [[1,2,2,1],
//  [3,1,2],
//  [1,3,2],
//  [2,4],
//  [3,1,2],
//  [1,3,1,1]]
// Output: 2
// Explanation: 

// Note:
// The width sum of bricks in different rows are the same and won't exceed INT_MAX.
// The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. 
// Total number of bricks of the wall won't exceed 20,000.
//===========================================================================================


class Solution {
public:
	/**
	* Idea: we could use a unordered_map<int, int> to record the distance to the left side and 
	* the number of this distance, where distance=0 and distance = n
	* 
	*/
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> helper;
        int n = wall.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
        	sum = 0;
        	for(int j = 0; j < wall[i].size(); j++){
        		sum += wall[i][j];
        		if(helper.find(sum) != helper.end()){
        			(helper.find(sum)->second)++;
        		}else{
        			helper.insert(make_pair(sum, 1));
        		}
        	}
        }
        int maxNum = 0;
        for(unordered_map<int, int>::iterator it = helper.begin(); it != helper.end(); ++it){
        	if(it->second > maxNum && it->first != sum){
        		maxNum = it->second;
        	}
        }
        return n-maxNum;
    }
};
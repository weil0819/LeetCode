/*

296. Best Meeting Point -- Hard
http://www.leetcode-free.com/problems/best-meeting-point.html

A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
The distance is calculated using Manhattan Distance, 
where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

*/

class Solution {
public:
	/*
	一维数组中找到距离所有点距离和最小的点一定落在median，
	比如[0,1,4,6]的最佳meeting point就是3这个点，距离就是6-0+4-1=9
	二维数组中使用Manhattan距离的话，那么最佳meeting point就是(x轴的median,y轴的median)
	所以，可以分别计算x和y的到median的和，然后相加
	*/
    int minTotalDistance(vector<vector<int>>& grid) {
    	int n = grid.size();
    	if(n == 0) return 0;
    	int m = grid[0].size();
    	vector<int> x, y;
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			if(grid[i][j] == 1){
    				x.push_back(i);
    				y.push_back(j);
    			}
    		}
    	}
    	return getMin(x)+getMin(y);
    }
private:
	int getMin(vector<int>& p){
		int n = p.size();
		int i = 0, j = n-1, ans = 0;

		sort(p.begin(), p.end());

		while(i < j){
			ans += (p[j--] - p[i++]);
		}
		return ans;
	}
};


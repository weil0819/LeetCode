/*

711. Number of Distinct Islands II -- Hard
https://www.leetfree.com/problems/number-of-distinct-islands-ii.html

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another 
if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) 
or reflection (left/right direction or up/down direction).

Example 1:
11000
10000
00001
00011
Given the above grid map, return 1. 

Notice that:
11
1
and
 1
11
are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, 
then two islands will have the same shapes.

Example 2:
11100
10001
01001
01110

Given the above grid map, return 2.

Here are the two distinct islands:
111
1
and
1
1

Notice that:
111
1
and
1
111

are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.

Note: The length of each dimension in the given grid does not exceed 50.

*/

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int R = grid.size();
        if(R == 0) return 0;
        int C = grid[0].size();

        set<vector<pair<int, int> > > islands;		// record all candidates

        for (int r = 0; r < R; ++r) {				// scan each grid
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 1) {
                    vector<pair<int, int> > island;	// store island
                    DFS(grid, r, c, r, c, island);	// DFS traversal
                    islands.insert(normalize(island));
                }
            }
        }
        return islands.size();						// return #island
    }

private:
    void DFS(vector<vector<int> > &grid, int r0, int c0, int r, int c, vector<pair<int, int> > &island) {
        int R = grid.size(), C = grid[0].size();
        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] <= 0) {
            return;
        }

        grid[r][c] = -1;								// flag visited

        island.push_back(make_pair(r - r0, c - c0));	// here, store relative coordinates

        for (int d = 0; d < 4; ++d) {					// scan 4 directions
            DFS(grid, r0, c0, r + delta[d][0], c + delta[d][1], island);
        }
    }

    vector<pair<int, int>> normalize(vector<pair<int, int>> &a) {
        vector<vector<pair<int, int>>> ret(8, vector<pair<int, int>>());

        for (auto &p : a) {								// scan each grid in island
            int x = p.first, y = p.second;
            ret[0].push_back(make_pair(x, y));			// generate 8 different shapes
            ret[1].push_back(make_pair(x, -y));
            ret[2].push_back(make_pair(-x, y));
            ret[3].push_back(make_pair(-x, -y));
            ret[4].push_back(make_pair(y, x));
            ret[5].push_back(make_pair(y, -x));
            ret[6].push_back(make_pair(-y, x));
            ret[7].push_back(make_pair(-y, -x));
        }

        for (int i = 0; i < 8; ++i) {					// scan each shape
            sort(ret[i].begin(), ret[i].end());

            int r_offset = 0 - ret[i][0].first, c_offset = 0 - ret[i][0].second;

            for (int j = 0; j < ret[i].size(); ++j) {	// transfer absolute coordinates into relative coordinates 
                ret[i][j].first += r_offset;
                ret[i][j].second += c_offset;
            }
        }

        sort(ret.begin(), ret.end());					// sort shapes and choose the first one
        return ret[0];
    } 
    
    int delta[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};

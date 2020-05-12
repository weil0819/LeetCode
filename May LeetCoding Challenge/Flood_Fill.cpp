/*
Flood Fill

@date: May 11, 2020

An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

*/

class Solution {
public:
    // BFS method: iterative
    // color the coordinates first and then push into Queue
    /*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int N = image.size();
        if(N == 0) return image;
        int M = image[0].size();
        if(image[sr][sc] == newColor) return image;
        
        queue<pair<int, int> > helper;
        helper.push(make_pair(sr, sc));
        
        int color = image[sr][sc];
        image[sr][sc] = newColor;        
        
        while(!helper.empty()) {
            int x = helper.front().first;
            int y = helper.front().second;
            helper.pop();
            
            // 4 directions
            if(x-1 >= 0 && image[x-1][y] == color) {
                helper.push(make_pair(x-1, y));
                image[x-1][y] = newColor;
            }
            if(x+1 < N && image[x+1][y] == color) {
                helper.push(make_pair(x+1, y));
                image[x+1][y] = newColor;
            }
            if(y-1 >= 0 && image[x][y-1] == color) {
                helper.push(make_pair(x, y-1));
                image[x][y-1] = newColor;
            }
            if(y+1 < M && image[x][y+1] == color) {
                helper.push(make_pair(x, y+1));
                image[x][y+1] = newColor;
            }            
        }
        return image;        
    }
    */
    
    //DFS method: recursive
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) {
            DFSUtil(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
    
private:
    void DFSUtil(vector<vector<int> >& image, int x, int y, int color, int newColor) {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != color) return ;
        image[x][y] = newColor;
        DFSUtil(image, x-1, y, color, newColor);
        DFSUtil(image, x+1, y, color, newColor);
        DFSUtil(image, x, y-1, color, newColor);
        DFSUtil(image, x, y+1, color, newColor);
    }
    
};



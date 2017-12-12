class Solution {
public:
    /**
    * Idea: straightforward traverse each vertex in matrix
    * 
    */
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > output(M);
        int n = M.size(), m = M[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int left = 0, right = 0, up = 0, down = 0, upLeft = 0, downLeft = 0, upRight = 0, downRight = 0;
                int count = 1;
                if(i-1 >= 0){
                    left = M[i-1][j];
                    ++count;
                    if(j-1 >= 0){
                        upLeft = M[i-1][j-1];
                        ++count;
                    }
                    if(j+1 < m){
                        downLeft = M[i-1][j+1];
                        ++count;
                    }
                }
                if(i+1 < n){
                    right = M[i+1][j];
                    ++count;
                    if(j-1 >= 0){
                        upRight = M[i+1][j-1];
                        ++count;
                    }
                    if(j+1 < m){
                        downRight = M[i+1][j+1];
                        ++count;
                    }
                }
                if(j-1 >= 0){
                    up = M[i][j-1];
                    ++count;
                }
                if(j+1 < m){
                    down = M[i][j+1];
                    ++count;
                }
                
                int sum = left + right + up+ down + upLeft + upRight + downLeft + downRight + M[i][j];
                int smoother = (int)floor(sum/count);
                output[i][j] = smoother;                               
            }
        }
        return output;
    }
};
class Solution {
public:
    /**
    * Idea: sequential scan each operation in ops and find the mins a and b
    * that means minA*minB is the final result
    */
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int a = m;
        int b = n;
        for(int k = 0; k < ops.size(); k++){
            int i = ops[k][0];
            int j = ops[k][1];
            if(i < a){
                a = i;
            }
            if(j < b){
                b = j;
            }
        }
        return a*b;
        
    }
};
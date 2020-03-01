class Solution {
public:
    /**
    * Idea: We can initialize the result with all 0,
    * and produce the result step by step 
    * We must produce the element in each layer from tail to start
    * eg, 1
    *     1 1
    *     1 2 1
    *     1 3 3 1
    *     1 4 6 4 1
    *     array[i] = array[i] + array[i-1]
    * If we calculate from start to tail, array[1]=1+3=4, array[2]=3+4=7
    * 
    */
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1, 0);
        output[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j >= 1; j--){
                output[j] += output[j-1];
            }
        }
        return output;
    }
};
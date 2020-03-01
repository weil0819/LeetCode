class Solution {
public:
    /**
    * Idea: In each row, the first and last element should be 1, other elements are equal to the sum of above two elements
    * We can use a vector<int> to record the elements in previous row.
    */
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > output;
        if(numRows == 0){
            return output;
        }
        vector<int> layerOne(1, 1);
        vector<int> layerTwo(2, 1);
        if(numRows == 1){
            output.push_back(layerOne);
            return output;
        }
        output.push_back(layerOne);
        output.push_back(layerTwo);
        vector<int> preVec(2, 1);
        for(int i = 3; i <= numRows; i++){
            vector<int> layer(i, 1);
            for(int j = 1; j < i-1; j++){
                layer[j] = preVec[j-1] + preVec[j];
            }
            output.push_back(layer);
            preVec = layer;
        }
        return output;
    }
};
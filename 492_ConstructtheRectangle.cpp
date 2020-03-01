class Solution {
public:
    /**
    * Idea: Given L*W=area and L>=W, object is to minimize (L-W)
    * initialize L as the ceil(sqrt(area)), and then add 1 each time until area%L=0
    */
    vector<int> constructRectangle(int area) {
        int L = (int)ceil(sqrt(area));        
        while(area%L != 0){
            ++L;
        }        
        vector<int> output;
        output.push_back(L);
        output.push_back(area/L);
        return output;
    }
};
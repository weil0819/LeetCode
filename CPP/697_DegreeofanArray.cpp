class Solution {
public:
    /**
    * Idea: first we count all positions of each element
    * then find the first and the last positions that max element appears 
    * here, we use only one hashmap to record these positions
    */
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int> > posMap;
        int n = nums.size(), maxFre = 0;
        for(int i = 0; i < n; i++){
            int t = nums[i];
            if(posMap.find(t) == posMap.end()){
                vector<int> tmp;
                tmp.push_back(i);
                posMap.insert(make_pair(t, tmp));
            }else{          
                posMap.find(t)->second.push_back(i);
            }
            if(posMap.find(t)->second.size() > maxFre){
                maxFre = posMap.find(t)->second.size();
            }
        }
        int output = INT_MAX;
        for(unordered_map<int, vector<int> >::iterator it = posMap.begin(); it != posMap.end(); ++it){
            int len = it->second.size();
            if(len == maxFre){
                int tmp = it->second[len-1] - it->second[0] + 1;
                if(tmp < output){
                    output = tmp;
                }
            }
        }
        return output;             
        
    }
};
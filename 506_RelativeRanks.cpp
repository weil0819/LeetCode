class Solution {
public:
    /**
    * Idea: use a map<int, int> to record the score and its original position
    * Here, map is sorted data structure which is in ascending order
    * By the way, we can try new data structure---priority-queue
    * http://www.cplusplus.com/reference/queue/priority_queue/
    * Attention: How to construct a vector: 
    *                       vector<int> second (4,100);                       // four ints with value 100
    *                       vector<int> third (second.begin(),second.end());  // iterating through second
    *                       vector<int> fourth (third);                       // a copy of third
    */
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> help;
        for(int i = 0; i < nums.size(); i++){
            help.insert(make_pair(nums[i], i));
        }
        vector<string> output(nums.size(), "");
        int ind = 1;
        for(map<int, int>::reverse_iterator rit = help.rbegin(); rit != help.rend(); ++rit){
            if(ind == 1){
                output[rit->second] = "Gold Medal";
                ++ind;
            }else if(ind == 2){
                output[rit->second] = "Silver Medal";
                ++ind;
            }else if(ind == 3){
                output[rit->second] = "Bronze Medal";
                ++ind;
            }else{
                output[rit->second] = to_string(ind);
                ++ind;
            }
        }
        return output;
        
    }
};
class Solution {
public:
    /**
    * Idea: 1.sort the array, the middle one must be majority element
    * 2. uses unordered_map to record the element and its number, when some element's number > n/2, stop
    */
    int majorityElement(vector<int>& nums) {
        // ==1
        
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
        
        
        // ==2
        /*
        unordered_map<int, int> help;
        for(int i = 0; i < nums.size(); i++){
            if(help.find(nums[i]) != help.end()){
                help.insert(make_pair(nums[i], 1));
            }else{
                ++help.find(nums[i])->second;
                if(help.find(nums[i])->second > nums.size()/2){
                    return nums[i];
                }
            }
        }
        return 0;
        */
    }
};
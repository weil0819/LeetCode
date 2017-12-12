class Solution {
public:
    /**
    * Idea: use an unordered_set to record the element in one array
    * and then check the other one
    * here, unordered_set and unordered_map both use hashtable to store elements not red-balck tree like set and map
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> help;
        for(int i = 0; i < nums1.size(); i++){
            help.insert(nums1[i]);
        }
        nums1.clear();
        for(int i = 0; i < nums2.size(); i++){
            if(help.find(nums2[i]) != help.end()){
                nums1.push_back(nums2[i]);
                help.erase(help.find(nums2[i]));
            }
        }
        return nums1;
    }
};
class Solution {
public:
    /**
    * Idea: use unordered_map<int, int> to record the element and its #element in nums1
    * If nums2 is in disk, we should pick up memory size block of nums2 to memory and count the number
    * My approach is O(n+m) time and O(n)
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> help;
        for(int i = 0; i < n; i++){
            ++help[nums1[i]];
        }
        vector<int> output;
        for(int i = 0; i < m; i++){
            if(help.find(nums2[i]) != help.end() && help.find(nums2[i])->second > 0){
                --help.find(nums2[i])->second;                
                output.push_back(nums2[i]);
            }
        }
        return output;
    }
};
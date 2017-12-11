//==========================================================================================
// 347. Top K Frequent Elements

// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//==========================================================================================

class Solution {
public:
	/**
	* Idea: use a unordered_map<int, int> to record the number of each element
	* using bucket sort, the size of bucket == the largest one among different integers
	* Since bucket[last] is the maximum value
	* 
	*/
    vector<int> topKFrequent(vector<int>& nums, int k) {  
    	vector<int> output; 

        int n = nums.size();
        if(n == 0){
        	return output;
        }

        unordered_map<int, int> help;		// <nums[i], #>
        for(int i = 0; i < n; i++){
        	++help[nums[i]];
        }

        vector<vector<int> > bucket(nums.size()+1);	// <#, integers>
        for(unordered_map<int, int>::iterator it = help.begin(); it != help.end(); ++it){
        	int num = it->second;
        	bucket[num].push_back(it->first);
        }

        int m = bucket.size();        
        for(int i = m-1; i >= 0; i--){
        	for(int j = 0; j < bucket[i].size(); j++){
        		output.push_back(bucket[i][j]);
        		if(output.size() == k){
        			return output;
        		}
        	}
        }
    }
};


/*

1207. Unique Number of Occurrences -- Easy
https://leetcode.com/problems/unique-number-of-occurrences/ 

Given an array of integers arr, write a function that returns true if and only if the number of occurrences of each value in the array is unique.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000

*/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // use a hashmap to keep <value, occurrence>
        unordered_map<int, int> UM;
        for(int i = 0; i < arr.size(); i++) {
            ++UM[arr[i]];            
        }
        // use a hashset to keep unique occurrence
        unordered_set<int> US;
        for(auto p: UM) {
            US.insert(p.second);
        }       
        
        // compare sizeof(UM) and sizeof(US)
        return UM.size() == US.size();
    }
};


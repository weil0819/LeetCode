//===========================================================================================
// 423. Reconstruct Original Digits from English

// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. 
// That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"

// Output: "012"
// Example 2:
// Input: "fviefuro"

// Output: "45"
//===========================================================================================

class Solution {
public:
    /**
    * Idea: we first enumerate the ten English digits as follows:
    *                                   zero, one, two, three, four, five, six, seven, eight, nine
    * the special char in each digit:   z,    ?    w,   ?      u,    ?     x,   ?      g,     ?
    * If we get 'h', it may be 3, 8
    * If we get 'o', it may be 0, 1, 2, 4 
    * If we get 'v', it may be 5, 7
    * If we get 's', it may be 6, 7
    * If we get 'i', it may be 5, 6, 8, 9
    * 
    */
    string originalDigits(string s) {
        unordered_map<char, int> helper;
        string res = "";
        int n = s.size();
        if(n == 0){
            return res;
        }
        for(int i = 0; i < n; i++){
            ++helper[s[i]];
        }

        vector<int> nums(10, 0);
        nums[0] = helper['z'];
        nums[2] = helper['w'];
        nums[4] = helper['u'];
        nums[6] = helper['x'];
        nums[8] = helper['g'];
        nums[1] = helper['o'] - nums[0] - nums[2] - nums[4];
        nums[3] = helper['h'] - nums[8];
        nums[5] = helper['f'] - nums[4];
        nums[7] = helper['s'] - nums[6];
        nums[9] = helper['i'] - nums[5] - nums[6] - nums[8];

        for(int i = 0; i < 10; i++){
            for(int j = nums[i]; j > 0; j--){
                res = res + to_string(i);
            }
        }

        return res;
    }
};
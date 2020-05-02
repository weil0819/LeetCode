/*
Jewels and Stones

@date: May 2, 2020

You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/

class Solution {
public:
    // Using set<char> to record different types of stones
    int numJewelsInStones(string J, string S) {
        unordered_set<char> help;
        for(auto j: J) {
            help.insert(j);
        }
        int res = 0;
        for(auto s: S) {
            if(help.find(s) != help.end()) {
                ++res;
            }
        }
        return res;
    }
};

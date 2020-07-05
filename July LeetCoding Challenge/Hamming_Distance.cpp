/*
Hamming Distance

@date: July 5, 2020

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/

class Solution {
public:
    // x ^ y and right shift 1 position each time
    int hammingDistance(int x, int y) {
        int res = 0;
        int xy = x ^ y;
        while(xy != 0) {
            res += (xy & 1);
            xy >>= 1;
        }
        return res;
    }
};

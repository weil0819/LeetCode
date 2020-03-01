/*

276. Paint Fence -- Easy
http://www.leetfree.com/problems/paint-fence.html

There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.

*/

/*

问题：n个柱子的围栏，用k种颜色涂色，不能有超过连续两个相同的颜色，求多少种不同涂色方案


在染一个柱子的时候, 要考虑是否和上一个柱子颜色相同：[两种不同状态--same和diff]
    --如果和上一个相同的话(same)，那么上一个有多少种和上上次不同的染色方案(diff)
    [上一个和上上次的颜色方案必须不同], 那么当前柱子也有多少种染色方案(same=diff).
    --如果和上一个不同的话(diff)，那么染色方案就为(k-1)*(之前总共多少染色方案).

*/
class Solution {
public:
    int numWays(int n, int k) {
        if(n==0 || k==0 || (k==1 && n>2)) return 0;
        int same = 0, diff = k, total = k;
        for(int i = 2; i <= n; i++)
        {
            same = diff;        // case 1: current post has the same color as the former one
            diff = (k-1)*total; // case 2: current post has different color as the former one
            total = same + diff;    // total possible colors of current post
        }
        return total;
    }
};
/*

339. Nested List Weight Sum -- Easy
https://www.leetfree.com/problems/nested-list-weight-sum.html

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

*/

/*
问题：已知嵌套列表，返回列表中数字*深度的累加和


递归问题：
使用一个变量deep表示当前的深度

初始时，deep=1
顺序遍历嵌套列表：
如果是数字，那么就直接计算累加和
如果是列表，那么就递归计算deep+1的新列表的累加和

*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
private:
	int depthSum(vector<NestedInteger>& nestedList, int deep){
		int res = 0;
		int n = nestedList.size();
		if(n == 0) return 0;
		for(int i = 0; i < n; i++){
			if(nestedList[i].isInteger()){
				res += nestedList[i].getInteger()*deep;
			}else{
				res += depthSum(nestedList[i].getList(), deep+1);
			}
		}
		return res;
	}
};


/*

246. Strobogrammatic Number -- Easy
http://www.leetfree.com/problems/strobogrammatic-number.html

A strobogrammatic number is a number that looks the same when rotated 180 degrees 
(looked at upside down).

Write a function to determine if a number is strobogrammatic. 
The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.

*/

/*
问题：如果一个数字旋转180度之后通同原来相同，那么它就是一个strobogrammatic数字
判断一个数字是不是strobogrammatic


0-9的数字中只有(0,0),(1,1),(6,9),(8,8),(9,6)满足strobogrammatic
所以使用unordered_map<int, int> hash存放上面5组
遍历num，如果i和n-i-1位置的值刚好是hash中的一对，那么就是strobogrammatic

*/
class Solution {  
public:  
    bool isStrobogrammatic(string num) {  
    	unordered_map<int, int> hash;
    	hash.insert(make_pair(0,0));
    	hash.insert(make_pair(1,1));
    	hash.insert(make_pair(6,9));
    	hash.insert(make_pair(9,6));
    	hash.insert(make_pair(8,8));

    	int n = num.size();
    	for(int i = 0; i < n; i++){
    		int n1 = num[i] - '0';
    		int n2 = num[n-1-i] - '0';
    		if(hash.find(n1) == hash.end() || hash.find(n2) == hash.end() || n2 != hash[n1]){
    			return false;
    		}
    	}
    	return true;
    }  
};


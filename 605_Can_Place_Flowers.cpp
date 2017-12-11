//===========================================================================================
// 605. Can Place Flowers
// Suppose you have a long flowerbed in which some of the plots are planted and some are not. 
// However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

// Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), 
// and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

// Example 1:
// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: True
// Example 2:
// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: False
// Note:
// The input array won't violate no-adjacent-flowers rule.
// The input array size is in the range of [1, 20000].
// n is a non-negative integer which won't exceed the input array size.
//===========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }
    	int m = flowerbed.size();
    	for(int i = 0; i < m; i++){
    		if(flowerbed[i] == 0){
    			int pre = i > 0 ? flowerbed[i-1] : -1;
    			int post = i < m-1 ? flowerbed[i+1] : -1;
    			if(pre == 0 && post == 0){
    				flowerbed[i] = 1;
    				n--;
    				if(n == 0){
    					return true;
    				}
    			}
                if(pre == -1 && post == 0){
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0){
                        return true;
                    }
                }
                if(pre == 0 && post == -1){
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0){
                        return true;
                    }                   
                }
                if(pre == -1 && post == -1){
                    flowerbed[i] = 1;
                    n--;
                    if(n == 0){
                        return true;
                    }                     
                }
    		}
    	}
    	return false;
    }
};

int main(){
	Solution sn;
	int a[] = {0,0,1,0,1};
	vector<int> flowerbed(a, a+5);
	cout<<sn.canPlaceFlowers(flowerbed, 1)<<endl;
	return 0;
}
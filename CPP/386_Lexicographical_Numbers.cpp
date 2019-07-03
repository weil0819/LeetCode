//===========================================================================================
// 386. Lexicographical Numbers

// Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: we first deal with the 1,10+,100+,...
	* and then handle the 2, 20+, 200+,...
	* we should first check whether val*10 can be in range[1,n], if yes, insert val*10;
	* else, we consider the number next to val, if this number > n, we should consider the next part (13->2)
	* if this number can be divided by 10 (109->110), we should consider the number which ignores tail 0
	* 
	*/
    vector<int> lexicalOrder(int n) {
    	vector<int> res(n, 0);
    	int val = 1;
        for(int i = 0; i < n; i++){
        	res[i] = val;
        	if(val*10 <= n){
        		val = val*10;
        	}else{
        		if(val == n){
        			val /= 10;
        		}
        		val += 1;					// 1,10,100,...,109,11,110,...
        		while(val%10 == 0){			// 109+1=110, we should record 110/10=11 first
        			val /= 10;
        		}
        	}
        }
        return res;
    }
};
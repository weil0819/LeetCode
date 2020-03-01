//===========================================================================================
// 241. Different Ways to Add Parentheses

// Given a string of numbers and operators, return all possible results from computing 
// all the different possible ways to group numbers and operators. The valid operators are +, - and *.


// Example 1
// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]


// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]
//===========================================================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* Idea: This is recursion problem
	* When it comes to an operation, we can divide the left-part and right-part,
	* and then compute the two parts recursively until only one integer
	* 
	*/
    vector<int> diffWaysToCompute(string input) {
    	vector<int> res;
    	int n = input.size();
    	for(int i = 0; i < n; i++){
    		char tmp = input[i];
    		if(tmp == '+' || tmp == '-' || tmp == '*'){
    			vector<int> res1 = diffWaysToCompute(input.substr(0, i));
    			vector<int> res2 = diffWaysToCompute(input.substr(i+1));
    			for(int j = 0; j < res1.size(); j++){
    				for(int k = 0; k < res2.size(); k++){
    					if(tmp == '+'){
    						res.push_back(res1[j]+res2[k]);
    					}else if(tmp == '-'){
    						res.push_back(res1[j]-res2[k]);
    					}else{
    						res.push_back(res1[j]*res2[k]);
    					}
    				}
    			}
    		}
    	}
    	if(res.empty()){					// if we recursively get the only one intger
    		res.push_back(stoi(input)); 
    	}
    	return res;
    }
};

int main(){
	Solution sn;
	vector<int> res = sn.diffWaysToCompute("2*3-4*5");
	for(int i = 0; i < res.size(); i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
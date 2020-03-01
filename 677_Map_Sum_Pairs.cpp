//==========================================================================================
// 677. Map Sum Pairs

// Implement a MapSum class with insert, and sum methods.

// For the method insert, you'll be given a pair of (string, integer). 
// The string represents the key and the integer represents the value. 
// If the key already existed, then the original key-value pair will be overridden to the new one.

// For the method sum, you'll be given a string representing the prefix, 
// and you need to return the sum of all the pairs' value whose key starts with the prefix.

// Example 1:
// Input: insert("apple", 3), Output: Null
// Input: sum("ap"), Output: 3
// Input: insert("app", 2), Output: Null
// Input: sum("ap"), Output: 5
//==========================================================================================
#include <iostream>
#include <unordered_map>
using namespace std;

class MapSum {
private:
    unordered_map<string, int> mp;

public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        if(mp.find(key) == mp.end()){
            mp.insert(make_pair(key, val));
        }else{
            mp[key] = val;
        }   
    }
    
    int sum(string prefix) {
        int len = prefix.size(), sum = 0;
        for(unordered_map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
            string tmp = it->first;
            if(tmp.substr(0, len) == prefix){
                sum += it->second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

 int main(){
     MapSum obj;
     obj.insert("apple", 3);
     cout<<obj.sum("ap")<<endl;
     return 0; 
 }

/*

281. Zigzag Iterator -- Medium
http://www.leetfree.com/problems/zigzag-iterator.html


Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, 
the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? 
How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. 
If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". 

For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].

*/

/*

用一个队列来保存给定的数组的迭代器的位置
queue<pair<vector<int>::iterator, vector<int>::iterator>> Q 
存放下一个位置以及结束位置

*/
class ZigzagIterator {
private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    	if(v1.size() != 0) Q.push(make_pair(v1.begin(), v1.end()));		// Q = [(1,end), (3, end)]
    	if(v2.size() != 0) Q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        int val = *Q.front().first;
        auto it1 = Q.front().first, it2 = Q.front().second;
        if(it1+1 != it2) Q.push(make_pair(it1+1, it2));		// Q = [(1,end), (3, end), (2, end)]
        Q.pop();											// Q = [(3, end), (2, end)]
        return val;
    }

    bool hasNext() {
    	return !Q.empty();
    }
};

/**
* Your ZigzagIterator object will be instantiated and called as such:
* ZigzagIterator i(v1, v2);
* while (i.hasNext()) cout << i.next();
*/

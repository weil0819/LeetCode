/*

251. Flatten 2D Vector -- Medium
http://www.leetfree.com/problems/flatten-2d-vector.html

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]

By calling next repeatedly until hasNext returns false, the order of elements 
returned by next should be: [1,2,3,4,5,6].

Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.

*/

/*

维护3个迭代器：iterStart, iterEnd, iter，分别指向vec2d的开始，vec2d结尾，移动
二维vector的迭代器与一维vector的迭代器：
iter1 = (*iter2).begin();		//初始

*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        if(vec2d.size() == 0) return;
        iterStart = vec2d.begin();
        iterEnd = vec2d.end();
        iter = (*iterStart).begin();		// (*iterStart) is the vector of current row
    }
 
    int next() {
    	iter++;
    	return *iter;
    }
 
    bool hasNext() {
    	while(iterStart != iterEnd && iter == (*iterStart).end()){	// iter moves to the end of each row
    		iterStart++;
    		iter = (*iterStart).begin();							// (*iterStart) is the vector of next row
    	}
    	return iterStart != iterEnd;
    }
private:
	vector<vector<int> >:iterator iterStart, iterEnd;
	vector<int>::iterator iter;
};
 
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

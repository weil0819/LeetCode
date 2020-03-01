/*

346. Moving Average from Data Stream -- Easy
http://www.leetfree.com/problems/moving-average-from-data-stream.html

Given a stream of integers and a window size, 
calculate the moving average of all integers in the sliding window.

For example,

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

class MovingAverage {
private:
	int len;		// sliding window size
	double sum;		// keep current sum value
	queue<int> Q;

public:
    MovingAverage(int size) {
    	len = size;
    }
    
    double next(int val) {
		sum += val;
		Q.push(val);				// push the new element into queue
		if(Q.size() > len){
			sum -= Q.front();		// pop the first element
			Q.pop();
		}    	
		return sum / Q.size();		// compute average value
    }
};

/** 
 * Your MovingAverage object will be instantiated and called as such: 
 * MovingAverage obj = new MovingAverage(size); 
 * double param_1 = obj.next(val); 
 */  
 
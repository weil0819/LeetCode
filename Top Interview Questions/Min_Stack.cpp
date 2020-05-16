/*
Min Stack
https://leetcode.com/explore/featured/card/top-interview-questions-easy/98/design/562/

@date: May 15, 2020

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/

class MinStack {
private:
    int minElem = INT_MAX;      // store current min element
    stack<int> S;               // store elements + min element
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        // If new element <= current min
        // store current min, and replace minElem with new element
        // Also need to push new element in stack
        if(x <= minElem) {
            S.push(minElem);
            minElem = x;
        }
        S.push(x);
    }
    
    void pop() {
        // If stack top element is the current min
        // pop out top element, and replace minElem with new stack top
        // at this moment, the new stack top is actually a min element not a real element
        // we need to pop out the new stack top 
        if(S.top() == minElem) {
            S.pop();
            minElem = S.top();
            S.pop();
        } else {
            S.pop();
        }        
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


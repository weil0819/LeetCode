/*
Min Stack
https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3292/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

class MinStack {
private:
    stack<int> S1;      // for elements in MinStack
    stack<int> S2;      // for current min element in MinStack
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        S1.push(x);
        if(S2.empty() || x <= getMin()) S2.push(x);
    }
    
    void pop() {
        if(S1.top() == getMin()) S2.pop();
        S1.pop();
    }
    
    int top() {
        return S1.top();
    }
    
    int getMin() {
        return S2.top();
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


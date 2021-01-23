#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <tuple>
#include <queue>
#include <stack>
#include <queue>

using namespace::std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
         minstk.push(INT32_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        if (x > minstk.top())
            minstk.push(minstk.top());
        else
            minstk.push(x);
    }
    
    void pop() {
        stk.pop(); 
        minstk.pop();
    }
    
    int top() {
        return stk.top(); 
    }
    
    int getMin() {
        return minstk.top();
    }
private:
    stack<int> stk, minstk; 
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    return 0;
}

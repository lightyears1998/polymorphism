// 最小栈
// https://leetcode-cn.com/problems/min-stack/
// 利用栈先进后出的性质维护数据结构。

#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX);
    }

    void push(int x) {
        stk.push(x);
        int prev_min = min_stk.top();
        int next_min = prev_min < x ? prev_min : x;
        min_stk.push(next_min);
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stk.top();
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

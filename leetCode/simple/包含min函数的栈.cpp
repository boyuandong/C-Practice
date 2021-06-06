/* 包含min函数的栈.cpp
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// using two stacks: one store data, the other one stores mins
#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mins;
    MinStack() {

    }
    
    void push(int x) {
        if(mins.empty() || x<mins.top())
            mins.push(x);
        else
            mins.push(mins.top());
        s.push(x);
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */


// using one stacks: push data and min into one data
class MinStackOne {
public:
    /** initialize your data structure here. */
    // stack<int> s;
    // stack<int> mins;
    stack<int> s;
    int Min=INT_MAX;
    MinStackOne() {

    }
    
    void push(int x) {
        // if(mins.empty() || x<mins.top())
        //     mins.push(x);
        // else
        //     mins.push(mins.top());
        // s.push(x);

        s.push(Min);
        if(x<Min) Min=x;
        s.push(x);
    }
    
    void pop() {
        // s.pop();
        // mins.pop();

        s.pop();
        Min = s.top();
        s.pop();
    }
    
    int top() {
        // return s.top();

        return s.top();
    }
    
    int min() {
        // return mins.top();

        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main()
{
    MinStack minS;
    minS.push(3);
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
    minS.push(5);
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
    minS.push(1);
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
    minS.pop();
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
    minS.pop();
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
    minS.pop();
    cout<<"top: "<<minS.top()<<" min: "<<minS.min()<<endl;
}
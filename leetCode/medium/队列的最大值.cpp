/* 队列的最大值.cpp
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <queue>
#include <deque>
using namespace std;
class MaxQueue
{
private:
    queue<int> MyQ;
    deque<int> MaxV;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return MyQ.empty() ? -1 : MaxV.front();
    }

    void push_back(int value)
    {
        MyQ.push(value);
        // 如果新的value大于deque尾端的值，那么deque一直进行pop_back操作，直到尾端的值大于等于value 或者为空
        while (!MaxV.empty() && value > MaxV.back())
            MaxV.pop_back();
        // 再将value压入deque的尾部
        MaxV.push_back(value);
    }

    int pop_front()
    {
        if (MyQ.empty())
            return -1;
        // 每次取max_value，返回deque首部的值
        int t = MyQ.front();
        MyQ.pop();
        // 当que进行pop操作时，如果que首部的值等于deque首部的值，那么deque同样需要进行pop_front操作
        if (t == MaxV.front())
            MaxV.pop_front();
        return t;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main()
{
    MaxQueue q;
    q.push_back(1);                //[1
    q.push_back(2);                //[1,2
    cout << q.max_value() << endl; //2
    cout << q.pop_front() << endl; //1     [2
    cout << q.max_value() << endl; //2
    cout << endl;
    MaxQueue q2;
    cout << q2.pop_front() << endl; //-1
    cout << q2.max_value() << endl; //-1
}
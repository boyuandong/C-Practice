/* 数据流中的中位数.cpp
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void PrintQ(priority_queue<int> q);
void PrintQ(priority_queue<int, std::vector<int>, std::greater<int> > q);
/* 用大顶堆+小顶堆方法，可以看作大顶堆是普通班，小顶堆是实验班。
新学生先入普通班（大顶堆），此时可能会失去平衡了，于是取大顶堆的第一个（班里最好的学生）加入实验班（小顶堆），
判断若数量过多（不是等于或多一个），取第一个（实验班里最差的学生）到普通班（大顶堆）里。 
取中位数的时候，若两堆数量相等，则各取堆顶取平均，若小顶比大顶多一，则多的那一个就是中位数。
插入数据O(logN)，取中位数O(1)
*/
class MedianFinder
{
private:
    priority_queue<int, std::vector<int>, std::greater<int> > right; //小->大
    priority_queue<int> left;                                        //大->小
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        left.push(num);
        right.push(left.top());
        left.pop();
        if (right.size() - left.size() > 1)
        {
            left.push(right.top());
            right.pop();
        }
        cout << "left: ";
        PrintQ(left);
        cout << "right: ";
        PrintQ(right);
    }

    double findMedian()
    {
        // if (left.size() == right.size())
        //     return double(left.top() + right.top()) / 2;
        if (right.size() > left.size())
            return double(right.top());
        else
            return double(left.top() + right.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
void PrintQ(priority_queue<int> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
void PrintQ(priority_queue<int, std::vector<int>, std::greater<int> > q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    cout << m.findMedian() << endl;
}
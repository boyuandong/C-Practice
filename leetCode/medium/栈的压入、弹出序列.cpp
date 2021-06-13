/* 栈的压入、弹出序列.cpp
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        /* : 把压栈的元素按顺序压入，当栈顶元素和出栈的第一个元素相同，则将该元素弹出，
        出栈列表指针后移并继续判断。最后判断出栈列表指针是否指向出栈列表的末尾即可。
        */
        if (pushed.size() != popped.size())
            return false;
        if (pushed.empty() && popped.empty())
            return true;
        stack<int> s1;
        int i, j = 0;
        for (i = 0; i < pushed.size(); i++)
        {
            s1.push(pushed[i]);
            while (!s1.empty() && j < popped.size() && popped[j] == s1.top())
            {
                s1.pop();
                j++;
            }
        }
        return j == popped.size();
    }
};

int main()
{
    Solution s;
    int test1[] = {1, 2, 3, 4, 5};
    int test2[] = {4, 5, 3, 2, 1};
    int test3[] = {4, 3, 5, 1, 2};
    vector<int> v1(test1, test1 + sizeof(test1) / sizeof(int));
    vector<int> v2(test2, test2 + sizeof(test2) / sizeof(int));
    vector<int> v3(test3, test3 + sizeof(test3) / sizeof(int));
    cout << (s.validateStackSequences(v1, v2) ? "true" : "false") << endl; // true
    cout << (s.validateStackSequences(v1, v3) ? "true" : "false") << endl; // false
}
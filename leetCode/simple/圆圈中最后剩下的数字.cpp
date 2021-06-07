/* 圆圈中最后剩下的数字.cpp
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
示例 1：

输入: n = 5, m = 3
输出: 3
示例 2：

输入: n = 10, m = 17
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lastRemaining1(int n, int m) {
        // 超时
        int i,k=0;
        int j=0;
        vector<int> v;
        for(i=0; i<n; i++)
        {
            v.push_back(i);
        }
        while(n>1)
        {
            k = (k+m-1)%n;
            v.erase(v.begin()+k);
            n--;
        }
        return v[0];
    }
    int lastRemaining(int n, int m)
    {
        // 新的一轮的开头是怎么指定的，每次都是固定地向前移位 m 个位置。
        // 然后我们从最后剩下的 3 倒着看，我们可以反向推出这个数字在之前每个轮次的位置。
        int ans=0; // 当只有一人的时候 胜利者下标肯定为0
        for(int i=2; i<=n; i++)
        {
            ans = (ans + m)%i; // 每多一个人，胜利者往右多动了m位，再对当前人数取余得到下标
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout<<s.lastRemaining1(5, 3)<<endl; // 3
    cout<<s.lastRemaining(5, 3)<<endl; // 3
    cout<<s.lastRemaining1(10, 17)<<endl; // 2
    cout<<s.lastRemaining(10, 17)<<endl; // 2
}
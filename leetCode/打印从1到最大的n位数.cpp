/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        int m=1;
        for(int i=0; i<n; i++)
            m *= 10;
        m -= 1;
        vector<int> ans(m, 0);
        for(int i=0; i<m; i++)
            ans[i] = i+1;
        return ans;
    }
};
void printVec(vector<int> num)
{
    int i;
    cout<<"[";
    for(i=0; i<num.size()-1; i++)
        cout<<num[i]<<" ";
    cout<<num[i]<<"]\n";
}
int main()
{
    Solution s;
    // s.printNumbers(1);
    printVec(s.printNumbers(1));
    printVec(s.printNumbers(2));
}
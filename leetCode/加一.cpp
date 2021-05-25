/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/plus-one
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        vector<int> new_v=digits;
        for(i=new_v.size()-1; i>=0; i--)
        {  
            new_v[i]++;
            if(new_v[i] <= 9)
                return new_v;
            else{
                new_v[i] = 0;
            }
        }
        new_v.insert(new_v.begin(), 1);
        return new_v;
    }
};

int main()
{
    int test0[] = {1,2,3, 4,3,2,1};
    vector<int> test1(test0, test0+3);      //[1,2,3] => [1,2,4]
    vector<int> test2(test0+3, test0+7);    //[4,3,2,1]=>[4,3,2,2]
    vector<int> test3(1,0);         // [0]=> [1]
    vector<int> test4(1,9);         // [9]=> [1,0]
    vector<int> test5(2,9);         // [9,9]=> [1,0,0]
    Solution s;
    // vector<int> result = s.plusOne(test1);
    // vector<int> result = s.plusOne(test2);
    // vector<int> result = s.plusOne(test3);
    // vector<int> result = s.plusOne(test4);
    vector<int> result = s.plusOne(test5);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    
}
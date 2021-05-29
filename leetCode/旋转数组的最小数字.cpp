/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // int ele[numbers.size()];
        for(int i=0; i<numbers.size()-1; i++)
        {
            if(numbers[i] > numbers[i+1])
                return numbers[i+1];
        }
        return numbers[0];
    }
};
int main()
{
    Solution s;
    int t1[] = {1,3,5};
    vector<int> test1(t1, t1+sizeof(t1)/sizeof(int));
    cout<<"1: "<<s.minArray(test1)<<endl;
    int t2[] = {3,4,5,1,2};
     vector<int> test2(t2, t2+sizeof(t2)/sizeof(int));
    cout<<"1: "<<s.minArray(test2)<<endl;
    int t3[] = {2,2,2,0,1};
     vector<int> test3(t3, t3+sizeof(t3)/sizeof(int));
    cout<<"0: "<<s.minArray(test3)<<endl;
}
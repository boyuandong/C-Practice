/* 左旋转字符串.cpp
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string reverseLeftWords1(string s, int n) {
        // using replace
        string rev;
        for(int i=0; i<n; i++)
            rev += s[i];
        s.replace(0, n, "");
        s += rev;
        return s;
    }
    string reverseLeftWords(string s, int n) {
        // using substr
        return s.substr(n,s.size()-n) + s.substr(0,n);
    }
};
int main()
{
    Solution s;
    string test0 = "abcdefg";
    string test1 = "lrloseumgh";
    cout<<test0<<"\n"<<s.reverseLeftWords(test0, 2)<<endl;
    cout<<test1<<"\n"<<s.reverseLeftWords(test1, 6)<<endl;
}
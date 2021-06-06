/*

*/
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        // Solution 1:
        // this sloution will get an run time error:

        // if(x<0)
        //     return false;
        // if(x==0)
        //     return true;
        // int rem=0, y=0;
        // int z=x;
        // while(z!=0)
        // {
        //     rem = z %10;
        //     y = y*10 + rem;
        //     z = z/10;
        // }
        // return x == y;
        
        // Solution 2:
        // convert int into a string
        string str = to_string(x);
        for(int i=0, j=str.size()-1; i<j; i++, j--)
        {
            if(str[i] != str[j])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    bool test1 = s.isPalindrome(121);
    bool test2 = s.isPalindrome(-121);
    bool test3 = s.isPalindrome(10);
    bool test4 = s.isPalindrome(-101);
    bool test5 = s.isPalindrome(12345678);
    cout<<test5<<endl;
}
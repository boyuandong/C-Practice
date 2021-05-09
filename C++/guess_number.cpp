#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int random_guess(int,int);
int main()
{
    int lower = 1, higher = 1000;
    int guess = random_guess(lower,higher);
    int flag;
    cout<<"Is this number your guess?\t"<<guess<<endl;
    cout<<"enter:\n1. Given is greater than guess;\n-1. Given is less than guess;\n0. Correct guess"<<endl;
    cin>>flag;

    while(flag !=0)
    {
        switch (flag)
        {
        case 1:
            // The number is greater than the guess
            higher = guess;
            break;

        case -1:
            // The number is less than the guess
            lower = guess;
            break;
        
        default:
            goto End;
        }

        guess = random_guess(lower,higher);
        cout<<"Is this number your guess?\t"<<guess<<endl;
        cin>>flag;

    }

    End: cout<<"Your number is: "<<guess<<endl;




}
int random_guess(int lower, int higher)
{
    //srand()可用来设置rand()产生随机数时的随机数种子。通过设置不同的种子，我们可以获取不同的随机数序列。
    // 可以利用srand((int)(time(NULL))的方法，利用系统时钟，产生不同的随机数种子。不过要调用time()，需要加入头文件< ctime >。
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行

    // 要取得[0,n)  就是rand（）%n     表示 从0到n-1的数
    // 要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
    // 要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a; 
    // 要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1; 
    // 通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。 
    // 要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。 
    // 要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)
    return (rand() % (higher - lower + 1) ) + lower;
}

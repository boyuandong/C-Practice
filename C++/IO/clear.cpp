// clear.cpp
// an example of using clear to continue code after end stream working state
#include <iostream>
using namespace std;
int main()
{
    int total = 0, n = 0, k;
    cout << "input:"<<endl;
    while (cin >> k)                // Use non-integer to end input, error! state error will get 1
    {
        total += k;
        n++;
    }


    cin.clear();                    // Restore input stream to working state
    cin.ignore(10, '\n');
    // cin.sync();                  // clear data
    // cin.ignore(10000, '\n');

    cout << "again:"<<endl;
    while (cin >> k)                // Use Ctrl-D to end input
    {
        total += k;
        n++;
    }
    cout << "total=" << total << "\tn=" << n << endl;
    return 0;
}
// algorithm_search_sort.cpp
// This is an example of search and sort by using <algorithm> in Library
/* There are 4 main algorithm used
    (1) find
    template<typename InputIterator, typename T> inline
    InputIterator find(InputIterator first, InputIterator last, const T& value)
    (2) find_if
    // Pred is a logic function    
    template<typename InputIterator, class T, class Predicate> inline
    InputIterator find_if(InputIterator first, InputIterator last, Predicate predicate) 
    (3) sort
    // version 1: ascending order 
    template<class RanIt>                   // Random Iterator
    void sort(RanIt first RanIt last);  
    // version 2: descending order, Pred is a logic function    
    template<class RanIt, class Pred>
    void sort(RanIt first, RndIt last, Pred pr);
    (4) binary_search
    // simialr to sort
    // version 1: FwdIt--ForwardIterator, search ascdening list
    template<class FwdIt, class T>
    bool binary_search(FwdIt first, FwdIt last, const T & val);
    // version 2: FwdIt--ForwardIterator, search descending list
    template<class FwdIt, class T, class Pred>
    bool bnary_search(FwdIt first, FwdIt last, cosnt T & val, Pred pr);
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool greater10(int);        // determine if greater than 10
bool inorder(int, int);     // determine if in descending order
int main()
{
    const int size=10;
    int i;
    int a[size] = {10, 3, 17, 6, 15, 8, 13, 34, 25, 2};
    vector<int> V(a, a+size);
    vector<int>::iterator location;
    cout<<"vector V contains:\n";
    for(i=0; i<size; i++)
        cout<<V[i]<<"\t";
    cout<<endl;
    location = find(V.begin(), V.end(), 15);            // find the position of 15
    if(location != V.end())                             // if 15 exist
        cout<<"Found 15 at location "<<(location - V.begin())<<endl;
    else    cout<<"15 not found"<<endl;
    location = find(V.begin(), V.end(), 100);           // search and find 100
    if(location != V.end())                             // if 15 exist
        cout<<"Found 100 at location "<<(location - V.begin())<<endl;
    else    cout<<"100 not found"<<endl;
    // search and find the first element that is greater than 10
    location = find_if(V.begin(), V.end(), greater10);
    if(location != V.end())                             // if 15 exist
        cout<<"The first greater than 10 is "<<*location<<" found at location "<<(location - V.begin())<<endl;
    else    cout<<"No value greater than 10 were found"<<endl;   
    sort(V.begin(), V.end());                           // sort vector, in ascending order
    cout<<"vector V after sort: \n";
    for(i=0; i<size; i++)
        cout<<V[i]<<"\t";
    cout<<endl;
    if(binary_search(V.begin(), V.end(), 13))           // binary search value 13
        cout<<"13 was found in V\n";
    else    cout<<"13 was not found in V\n";
    if(binary_search(V.begin(), V.end(), 50))           // binary search value 50
        cout<<"50 was found in V\n";
    else    cout<<"50 was not found in V\n";
    sort(V.begin(), V.end(), inorder);                  // sort vector in descending order
        cout<<"vector V after sort inorder: \n";
    for(i=0; i<size; i++)
        cout<<V[i]<<"\t";
    cout<<endl;
    if(binary_search(V.begin(), V.end(), 8, inorder))           // binary search value 8 for a descending order vector
        cout<<"8 was found in V\n";
    else    cout<<"8 was not found in V\n";
}
// determine if greater than 10
bool greater10(int value)
{   return value > 10; }     
// determine if in descending order
bool inorder(int a, int b)
{ return a>b; } 
// bubble sort 冒泡排序     O(n^2)
/*
Keep compare a[i] and a[i+1] 
So that keep the last element(s) sorted each time
until all sorted.
1. comparing a[0] and a[1]
    if a[0]>a[1] exchange the two
    keep comparing until a[n-2] and a[n-1]
    will put the greatest ele at a[n-1] (OR a[n-1] is sorted)
2. keep same comparing with a[0]...a[n-2]
    a[n-2] is sorted
...
a[0] ... a[n-1] all sorted
*/

void sort(int x[], int num)
{
    int i,j, temp;
    for(i = 1; i<num; i++)          // for 1...n-1
    {
        for(j=0; j<num-i; j++)      // for 0...n-i, each time comparing everything before i, keep getting sorted a[i]
        {
            if(x[j]>x[j+1])             // keep getting the greatest ele sorted and put it at a[i]
            {
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }

}
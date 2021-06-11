// bubble sort 冒泡排序     O(n^2)
// 比较相邻的元素，如果反序则交换，过程也是分为有序区和无序区，
// 初始时有序区为空，所有元素都在无序区，经过第一趟后就能找出最大的元素，然后重复便可
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
    int i, temp, work;
    for(int pass = 1; pass<num; pass++)
    {
        work = 1;
        for(i=0; i<num-pass; i++)
        {
            if(x[i]>x[i+1])
            {
                temp = x[i];
                x[i] = x[i+1];
                x[i+1] = temp;
                work = 0;
            }
        }
        if(work) break;         // stop when all sorted (no more exchanges)
    }

}
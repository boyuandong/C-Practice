// select sort 选择排序     O(n^2)
// descending order  从大到小
// ascending order 从小到大
// 在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；
// 然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，依次类推，
// 直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止
/* select sorting an array a[n]
for(i=0;i<n-1;i++)
{
    find the smallest/greatest element a[t] form a[i]...a[n-1]
    exchange a[t] and a[i]
}
find the smallest(greatest) element
for(j=i+1;j<n;j++)
{
    if(a[j]<a[t]) t=j
    OR GREATEST
    if(a[j]>a[t]) t=j
}
*/
void sort(int x[], int num)
{
    int min, t;
    for(int i=0;i<num-1; i++)
    {
        t=i;
        for(int j=i+1;j<num;j++)
        {
            if(x[j]<x[t]) t=j;
        }
        if(t!= i)
        {
            min = x[i];
            x[i] = x[t];
            x[t] = min;
        }
    }

    return;
}


// insert_sort.cpp
// 插入排序 
// 整个序列分为有序区和无序区，取第一个元素作为初始有序区，然后第二个开始，依次插入到有序区的合适位置，直到排好序
// time complexity: (N^2)
void sort(int x[], int num)
{
    for(int i=1; i<=num; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(x[j] < x[j-1])
            {
                int temp = x[j];
                x[j] = x[j-1];
                x[j-1] = temp;
            }
        }
    }
}
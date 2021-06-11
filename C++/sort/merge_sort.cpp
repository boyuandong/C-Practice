// merge_sort.cpp
// 归并排序的基本思想是将若干个序列进行两两归并，直至所有待排序记录都在一个有序序列为止
// time: O(NlogN)
void mergeSort(int x[], int l, int r);
void merge(int x[], int l, int m, int r);
void sort(int x[], int num)
{
    mergeSort(x, 0, num - 1);
}
void mergeSort(int x[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(x, l, m);
    mergeSort(x, m + 1, r);
    /* Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)*/
    merge(x, l, m, r);
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int x[], int l, int m, int r)
{
    int n1 = m - l + 1; // len of first arr
    int n2 = r - m;     // len of second arr
    // create two temp arrays, first and second;
    int L[n1], R[n2];
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = x[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = x[m + 1 + i];

    // Merge the temp arrays back into arr[l..r]
    int i = 0; // index of L[]
    int j = 0; // index of R[]
    int k = l; // index of x[] !!!!! from the l
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            x[k] = L[i];
            i++;
        }
        else
        {
            x[k] = R[j];
            j++;
        }
        k++;
    }
    // when there are left in L[]
    while (i < n1)
    {
        x[k] = L[i];
        i++;
        k++;
    }
    // when there are left in R[]
    while (j < n2)
    {
        x[k] = R[j];
        j++;
        k++;
    }
}
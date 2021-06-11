// quick_sort.cpp
// 快速排序
/* 
快速排序首先选一个轴值(pivot，也有叫基准的)，将待排序记录划分成独立的两部分，
左侧的元素均小于轴值，右侧的元素均大于或等于轴值，然后对这两部分再重复，直到整个序列有序
过程是和二叉搜索树相似，就是一个递归的过程
time complexity: O(NlogN)
1. Always pick first element as pivot.
2. Always pick last element as pivot (implemented below)
3. Pick a random element as pivot.
4. Pick median as pivot.
*/
int partition(int x[], int low, int high);
void quick_sort(int x[], int low, int high);
void sort(int x[], int num)
{
    quick_sort(x, 0, num - 1);
}
// Basically put each element at the right place
void quick_sort(int x[], int low, int high)
{
    //  low  --> Starting index,  high  --> Ending index
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now
           at right place */
        int pi = partition(x, low, high);

        quick_sort(x, low, pi - 1);  // Before pi
        quick_sort(x, pi + 1, high); // After pi
    }
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int x[], int low, int high)
{
    int temp;
    // pivot (Element to be placed at right position)
    int pivot = x[high];
    int i = (low - 1); // Index of smaller element and indicates the
                       // right position of pivot found so far
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (x[j] < pivot)
        {
            i++; // increment index of smaller element
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }
    // put the right place of pivot
    temp = x[i + 1];
    x[i + 1] = x[high];
    x[high] = temp;

    // return the position of pivot
    return (i + 1);
}
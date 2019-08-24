//写法一：
void insertion_sort(int a[], int n)
{
    int i, j, v;
    for (i = 1; i < n; i++)
    {
        //如果第i个元素小于第j个，则第j个向后移动
        for (v = a[i], j = i - 1; j >= 0 && v < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = v;
    }
}

//写法二：
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--) //有序前缀[0, i)
        {
            // 后序的首元素arr[i] 找到合适的插入位置
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
        // 内存for结束后 有序前缀范围扩大至[0, i]
    }
}
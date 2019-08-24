//写法一：
void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int i = l;
    int j = r;
    int key = a[l]; //选择第一个数为key

    while (i < j)
    {

        while (i < j && a[j] >= key) //从右向左找第一个小于key的值
            j--;
        if (i < j)
        {
            a[i] = a[j];
            i++;
        }

        while (i < j && a[i] < key) //从左向右找第一个大于key的值
            i++;

        if (i < j)
        {
            a[j] = a[i];
            j--;
        }
    }
    //i == j
    a[i] = key;
    quickSort(a, l, i - 1); //递归调用
    quickSort(a, i + 1, r); //递归调用
}
//写法二：
int mpartition(int a[], int l, int r)
{
    int pivot = a[l];

    while (l < r)
    {
        while (l < r && pivot <= a[r])
            r--;
        if (l < r)
            a[l++] = a[r];
        while (l < r && pivot > a[l])
            l++;
        if (l < r)
            a[r--] = a[l];
    }
    a[l] = pivot;
    return l;
}

void quick_sort(int a[], int l, int r)
{

    if (l < r)
    {
        int q = mpartition(a, l, r);
        quick_sort(a, l, q - 1);
        quick_sort(a, q + 1, r);
    }
}
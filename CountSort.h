void findArrMaxMin(int a[], int size, int *min, int *max)
{
    if (size == 0)
    {
        return;
    }
    if (size == 1)
    {
        *min = *max = a[0];
        return;
    }

    *min = a[0] > a[1] ? a[1] : a[0];
    *max = a[0] <= a[1] ? a[1] : a[0];

    int i, j;
    for (i = 2, j = 3; i < size, j < size; i += 2, j += 2)
    {
        int tempmax = a[i] >= a[j] ? a[i] : a[j];
        int tempmin = a[i] < a[j] ? a[i] : a[j];

        if (tempmax > *max)
            *max = tempmax;
        if (tempmin < *min)
            *min = tempmin;
    }

    //如果数组元素是奇数个，那么最后一个元素在分组的过程中没有包含其中，
    //这里单独比较
    if (size % 2 != 0)
    {
        if (a[size - 1] > *max)
            *max = a[size - 1];
        else if (a[size - 1] < *min)
            *min = a[size - 1];
    }
}

void count_sort(int a[], int b[], int n)
{
    int max, min;
    findArrMaxMin(a, n, &min, &max);
    int numRange = max - min + 1;
    int *counter = new int[numRange];

    int i, j, k;
    for (k = 0; k < numRange; k++)
        counter[k] = 0;

    for (i = 0; i < n; i++)
        counter[a[i] - min]++;

    for (k = 1; k < numRange; k++)
        counter[k] += counter[k - 1];

    for (j = n - 1; j >= 0; j--)
    {
        int v = a[j];
        int index = counter[v - min] - 1;
        b[index] = v;
        counter[v - min]--;
    }
}
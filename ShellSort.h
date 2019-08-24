//写法一：
void shell_sort1(int a[], int n)
{
    int d, i, j, temp;                 //d为增量
    for (d = n / 2; d >= 1; d = d / 2) //增量递减到1使完成排序
    {
        for (i = d; i < n; i++) //插入排序的一轮
        {
            temp = a[i];
            for (j = i - d; (j >= 0) && (a[j] > temp); j = j - d)
            {
                a[j + d] = a[j];
            }
            a[j + d] = temp;
        }
    }
}
//写法二：
void shell_sort2(int array[], int lenth)
{

    int temp = 0;
    int incre = lenth;

    while (true)
    {
        incre = incre / 2;

        for (int k = 0; k < incre; k++)
        { //根据增量分为若干子序列

            for (int i = k + incre; i < lenth; i += incre)
            {

                for (int j = i; j > k; j -= incre)
                {
                    if (array[j] < array[j - incre])
                    {
                        temp = array[j - incre];
                        array[j - incre] = array[j];
                        array[j] = temp;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if (incre == 1)
        {
            break;
        }
    }
}
//A:原数组temp:临时数组
//n:序列的数字个数
//k:最大的位数2
//r:基数10
//cnt:存储bin[i]的个数
void RadixSort(int A[], int temp[], int n, int k, int r, int cnt[])
{

    //A:原数组
    //temp:临时数组
    //n:序列的数字个数
    //k:最大的位数2
    //r:基数10
    //cnt:存储bin[i]的个数

    for (int i = 0, rtok = 1; i < k; i++, rtok = rtok * r)
    {

        //初始化
        for (int j = 0; j < r; j++)
        {
            cnt[j] = 0;
        }
        //计算每个箱子的数字个数
        for (int j = 0; j < n; j++)
        {
            cnt[(A[j] / rtok) % r]++;
        }
        //cnt[j]的个数修改为前j个箱子一共有几个数字
        for (int j = 1; j < r; j++)
        {
            cnt[j] = cnt[j - 1] + cnt[j];
        }
        for (int j = n - 1; j >= 0; j--)
        { //重点理解
            cnt[(A[j] / rtok) % r]--;
            temp[cnt[(A[j] / rtok) % r]] = A[j];
        }
        for (int j = 0; j < n; j++)
        {
            A[j] = temp[j];
        }
    }
}
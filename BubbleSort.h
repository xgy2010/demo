#include <iostream>
using namespace std;
//优化一：如果某一轮两两比较中没有任何元素交换，这说明已经都排好序了，算法结束，
//      可以使用一个Flag做标记，默认为false，如果发生交互则置为true，每轮结束时检测Flag，
//      如果为true则继续，如果为false则返回。

void BubbleSort1(int *arr,int len)
{

    int temp;     //临时变量
    bool flag; //是否交换的标志
    for (int i = 0; i < len - 1; i++)
    { //表示趟数，一共 len-1 次

        // 每次遍历标志位都要先置为false，才能判断后面的元素是否发生了交换
        flag = false;

        for (int j = len - 1; j > i; j--)
        { //选出该趟排序的最大值往后移动

            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = true; //只要有发生了交换，flag就置为true
            }
        }
        // 判断标志位是否为false，如果为false，说明后面的元素已经有序，就直接return
        if (!flag)
        {
            break;
        }
    }
}

//优化二：某一轮结束位置为j，但是这一轮的最后一次交换发生在lastSwap的位置，
//       则lastSwap到j之间是排好序的，下一轮的结束点就不必是j--了，而直接到lastSwap即可，代码如下：

void BubbleSort2(int *a, int n)
{
    int i, j, lastSwap, tmp;
    for (j = n - 1; j > 0; j = lastSwap)
    {
        lastSwap = 0; //每一轮要初始化为0，防止某一轮未发生交换，lastSwap保留上一轮的值进入死循环
        for (i = 0; i < j; i++)
        {
            if (a[i] > a[i + 1])
            {
                tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp; 
                lastSwap = i;//最后一次交换位置的坐标
            }
        }
    }
}



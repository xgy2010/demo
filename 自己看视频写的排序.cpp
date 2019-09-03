#include <iostream>
using namespace std;
#include <vector>
#include <sys/timeb.h>
#include <time.h>

void myPrint(vector<int>& v) //输出
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//冒泡
void bubbleSort(vector<int>& v)
{
	//int flag = 1;//0表示没有排好
	for (unsigned int i = 0; i < v.size()/*&&flag*/; i++)
	{
		//flag = 0;
		for (unsigned int j = i + 1; j < v.size(); j++)
		{
			if (v[i] > v[j])
			{
				//flag = 1;
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
}

//选择
void selectSort(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		int min = i;
		for (unsigned int j = i + 1; j < v.size(); j++)
		{
			if (v[min] > v[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}
}

//插入
void insertSort(vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int tem = v[i];
		int j;
		for (j = i - 1; j >= 0 && tem < v[j]; j--)
		{
			v[j + 1] = v[j];
		}
		v[j + 1] = tem;
	}
}

//希尔
void shellSort(vector<int>& v)
{
	int increasement = v.size();
	while (true)
	{
		increasement = increasement / 3 + 1;
		for (int i = 0; i < increasement; i++) //分为increasement组
		{
			//内部进行插入排序
			for (int j = i + increasement; j < v.size(); j += increasement)
			{
				if (v[j] < v[j - increasement])
				{
					int temp = v[j];
					int k;
					for (k = j - increasement; k >= 0 && temp < v[k]; k -= increasement)
					{
						v[k + increasement] = v[k];
					}
					v[k + increasement] = temp;
				}
			}
		}
		//increasement / 3 + 1最终会变为1，且始终为1，
		//但等于1时只循环一次就必须退出，故加了一个退出条件；
		if (increasement == 1)
		{
			break;
		}
	}
}

//快速
void quickSort(vector<int>& v, int start, int end)
{
	int i = start, j = end;
	if (i < j)
	{
		int base = v[start];
		while (i < j)
		{
			//从右向左找比base小的数
			while (base <= v[j] && i < j)
			{
				j--;
			}
			//填坑
			if (i < j)
			{
				v[i] = v[j];
				i++;
			}
			//从左向右找比base大的数
			while (base > v[i] && i < j)
			{
				i++;
			}
			//填坑
			if (i < j)
			{
				v[j] = v[i];
				j--;
			}
		}
		v[i] = base; //找到了base在序列中的位置，左边的比base都小，右边的比base都大
		quickSort(v, start, i - 1);
		quickSort(v, i + 1, end);
	}
}

//归并排序
void merge(vector<int>& v, int start, int end, int middle, vector<int>& v2)
{
	int i_start = start;
	int i_end = middle;
	int j_start = middle + 1;
	int j_end = end;
	//开始合并两个序列
	int length = 0;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (v[i_start] < v[j_start])
		{
			v2[length] = v[i_start];
			i_start++;
			length++;
		}
		else
		{
			v2[length] = v[j_start];
			j_start++;
			length++;
		}
	}
	//将i或j剩余序列加入到v2后面
	while (i_start <= i_end)
	{
		v2[length] = v[i_start];
		i_start++;
		length++;
	}
	while (j_start <= j_end)
	{
		v2[length] = v[j_start];
		j_start++;
		length++;
	}
	//覆盖原来空间v
	for (int i = 0; i < length; i++)
	{
		v[start + i] = v2[i];
	}
}

void mergeSort(vector<int>& v, int start, int end, vector<int>& v2)
{
	if (start >= end)
	{
		return;
	}
	int middle = (start + end) / 2;
	mergeSort(v, start, middle, v2); //左边
	mergeSort(v, middle + 1, end, v2); //右边
	merge(v, start, end, middle, v2);
}

//堆排序
void Swap_i_j(vector<int>& v, int i, int j)
{
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void heapAdjust(vector<int>& v, int index,int len)
{
	//因为节点从0开始，所以左孩子节点=*2+1；
	int max = index;
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;

	if (lchild <= len && v[max] < v[lchild])
	{
		max = lchild;
	}
	if (rchild <= len && v[max] < v[rchild])
	{
		max = rchild;
	}
	if (max != index)
	{
		Swap_i_j(v, max, index);
		heapAdjust(v, max,len);
	}
}

void heapSort(vector<int>& v)
{
	//初始化为大顶堆
	for (int i = v.size() / 2 - 1; i >= 0; i--)
	{
		heapAdjust(v, i,v.size()-1);
	}
	//将0位置的最大值和最后一个节点交换.之后再将0位置的第二大的值与倒数第二个节点交换
	for (int i = v.size() - 1; i >=0; i--)
	{
		Swap_i_j(v, 0,  i);
		heapAdjust(v, 0,i-1);
	}
}

int main(int argc, char* argv[])
{
	struct timeb t1, t2;

	vector<int> v;
	vector<int> v2; //辅助空间
	srand((unsigned int)time(nullptr));
	for (unsigned int i = 10; i > 0; i--)
	{
		v.push_back(i);
	}
	v2.resize(v.size());
	cout << "排序前：" << endl;
	myPrint(v);
	cout << "排序后：" << endl;
	ftime(&t1);
	//bubbleSort(v);
	//selectSort(v);
	//insertSort(v);
	//shellSort(v);
	//quickSort(v, 0, v.size() - 1);
	//mergeSort(v, 0, v.size() - 1, v2);
	//heapSort(v);
	ftime(&t2);
	myPrint(v);

	cout << "花费了：" << t2.time * 1000 + t2.millitm - t1.time * 1000 - t1.millitm << "ms" << endl;
	system("pause");
	return 0;
}

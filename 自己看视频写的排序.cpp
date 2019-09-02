#include <iostream>
using namespace std;
#include <vector>
#include <sys/timeb.h>
#include <time.h>

void myPrint(vector<int>& v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

//ð��
void bubbleSort(vector<int>& v)
{
	//int flag = 1;//0��ʾû���ź�
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

//ѡ��
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

//����
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

//ϣ��
void shellSort(vector<int>& v)
{
	int increasement = v.size();
	while (true)
	{
		increasement = increasement / 3 + 1;
		for (int i = 0; i < increasement; i++) //��Ϊincreasement��
		{
			//�ڲ����в�������
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
		//increasement / 3 + 1���ջ��Ϊ1����ʼ��Ϊ1��
		//������1ʱֻѭ��һ�ξͱ����˳����ʼ���һ���˳�������
		if (increasement == 1)
		{
			break;
		}
	}
}

//����
void quickSort(vector<int>& v, int start, int end)
{
	int i = start, j = end;
	if (i < j)
	{
		int base = v[start];
		while (i < j)
		{
			//���������ұ�baseС����
			while (base <= v[j] && i < j)
			{
				j--;
			}
			//���
			if (i < j)
			{
				v[i] = v[j];
				i++;
			}
			//���������ұ�base�����
			while (base > v[i] && i < j)
			{
				i++;
			}
			//���
			if (i < j)
			{
				v[j] = v[i];
				j--;
			}
		}
		v[i] = base; //�ҵ���base�������е�λ�ã���ߵı�base��С���ұߵı�base����
		quickSort(v, start, i - 1);
		quickSort(v, i + 1, end);
	}
}

//�鲢����
void merge(vector<int>& v, int start, int end, int middle, vector<int>& v2)
{
	int i_start = start;
	int i_end = middle;
	int j_start = middle + 1;
	int j_end = end;
	//��ʼ�ϲ���������
	int length = 0;
	while (i_start <= i_end && j_start <= j_end)
	{
		if (v[i_start] <v[ j_start])
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
	//��i��jʣ�����м��뵽v2����
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
	//����ԭ���ռ�v
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
	mergeSort(v, start, middle, v2); //���
	mergeSort(v, middle + 1, end, v2); //�ұ�
	merge(v, start, end, middle, v2);
}

int main(int argc, char* argv[])
{
	struct timeb t1, t2;

	vector<int> v;
	vector<int> v2; //�����ռ�
	srand((unsigned int)time(nullptr));
	for (unsigned int i = 10; i > 0; i--)
	{
		v.push_back(i);
	}
	v2.resize(v.size());
	cout << "����ǰ��" << endl;
	myPrint(v);
	cout << "�����" << endl;
	ftime(&t1);
	//bubbleSort(v);
	//selectSort(v);
	//insertSort(v);
	//shellSort(v);
	//quickSort(v, 0, v.size() - 1);
	mergeSort(v, 0, v.size() - 1, v2);
	ftime(&t2);
	myPrint(v);

	cout << "�����ˣ�" << t2.time * 1000 + t2.millitm - t1.time * 1000 - t1.millitm << "ms" << endl;
	system("pause");
	return 0;
}

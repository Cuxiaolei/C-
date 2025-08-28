#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
// #include <iostream>
#include <windows.h>
#include <sys/timeb.h>

#define MAX1 100000
#define MAX2 100
using namespace std;


typedef int SortType;

//获取当前系统时间
long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return (long)(tb.time * 1000 + tb.millitm);
}

//定时�?( 不会阻塞主函数运�?)
int Timer(time_t duration, int id)
{
	//使用静态初始时�?  static定义会自动初始化
	static time_t startime[10];
	time_t endtime = clock();
	if (endtime - startime[id] >= duration)
	{
		startime[id] = endtime;
		return 1;
	}
	return 0;
}

//计时程序
time_t GetTime()
{
	time_t count = clock();
	return count / 1000;
}

//时间函数测试
void Timetest()
{
	//当前时间
	time_t time0;
	time0 = time(NULL);
	struct tm* systemtime = localtime(&time0);
	cout << "date:";
	cout << systemtime->tm_year + 1900 << "." << systemtime->tm_mon + 1 << "." << systemtime->tm_mday << endl;
	cout << "星期" << systemtime->tm_wday << endl;
	cout << "今年�?" << systemtime->tm_yday + 1 << "�?" << endl;
	cout << "time:";
	cout << systemtime->tm_hour << ":" << systemtime->tm_min << ":" << systemtime->tm_sec << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << endl;
	}
	while (1)
	{
		cout << "666666";
		//Sleep(3000);
		if (Timer(30, 0))
		{
			cout << "我最牛逼！！！";
		}
		//经过3000毫秒后执�?	�?1传过去，即开始时startime[1] = 0固定不变; 当endtime �?3000时endtime - statime = 3000执行
		if (Timer(30, 1))
		{
			break;
		}

	}

	while (1)
	{
		cout << GetTime() << endl;
		if (GetTime() == 3)
		{
			break;
		}
	}


}

void Merge(int arr[], int start, int end, int mid, int* temp)
{
	int Lstart = start;
	int Lend = mid;
	int Rstart = mid + 1;
	int Rend = end;

	int len = 0;	//temp数组的大�?
	//合并两个有序序列
	while (Lstart <= Lend && Rstart <= Rend)
	{
		if (arr[Lstart] < arr[Rstart])
		{
			temp[len] = arr[Lstart];
			len++;
			Lstart++;
		}
		else
		{
			temp[len] = arr[Rstart];
			len++;
			Rstart++;
		}
	}

	//左边剩余序列
	while (Lstart <= Lend)
	{
		temp[len] = arr[Lstart];
		len++;
		Lstart++;
	}

	//右边剩余序列
	while (Rstart <= Rend)
	{
		temp[len] = arr[Rstart];
		len++;
		Rstart++;
	}

	//辅助空间数据覆盖原空�?
	for (int i = 0; i < len; i++)
	{
		arr[start + i] = temp[i];
	}
}






//冒泡排序
void BubbleSort(SortType arr[], SortType len)
{

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//冒泡排序（优化版�?
void BubbleSort1(SortType arr[], SortType len)
{
	int flag = 0;
	for (int i = 0; i < len && flag == 0; i++)
	{
		flag = 1;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 0;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//选择排序
void SlectSort(SortType arr[], SortType len)
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr[min], arr[i]);
		}
	}
}

//插入排序
void InsertSort(SortType arr[], SortType len)
{
	int j;
	for (int i = 1; i < len; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			int t = arr[i];
			for (j = i - 1; j >= 0 && t < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = t;
		}
	}
}

//希尔排序
void ShellSort(SortType arr[], SortType len)
{
	int increase = len;
	int i, j, k;
	do
	{
		increase = increase / 3 + 1;
		for (i = 0; i < increase; i++)
		{
			for (j = i + increase; j < len; j += increase)
			{
				if (arr[j - increase] > arr[j])
				{
					int t = arr[j];
					for (k = j - increase; k >= 0 && t < arr[k]; k -= increase)
					{
						arr[k + increase] = arr[k];
					}
					arr[k + increase] = t;
				}
			}
		}
	} while (increase > 1);
}

//快速排�?(分治�? + 挖坑填数)
void QuickSort(SortType arr[], SortType start, SortType end)
{
	if (start == end) return;
	SortType i = start;
	SortType j = end;
	//基准数（将首个数挖空�?
	SortType temp = arr[i];
	if (i < j)
	{
		//直到 i == j
		while (i < j)
		{
			//从右向左找比基准数小的数
			while (i < j && arr[j] >= temp)
			{
				j--;
			}
			//找到之后将这个数填在左边 并挖空此时的arr[j]
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}
			//从左向右找比基准数大的数
			while (i < j && arr[i] < temp)
			{
				i++;
			}
			//找到之后将这个数放在右边的坑�? 并挖空此时的arr[i]
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}

		//当i == j
		//把基准数放在i或j的位�?
		arr[i] = temp;

		//对左半部�?
		QuickSort(arr, start, i - 1);
		//对右半部�?
		QuickSort(arr, i + 1, end);
	}
}

//归并排序
void MergeSort(int arr[], int start, int end, int* temp)//temp为辅助空�?
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;
	//分组

	//左半�?
	MergeSort(arr, start, mid, temp);
	//右半�?
	MergeSort(arr, mid + 1, end, temp);

	//合并
	Merge(arr, start, end, mid, temp);
}






















//打印数组
void print(SortType arr[], SortType n)
{
	for (SortType i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}




//排序算法测试(非打印版)
void SortTest1()
{
	int arr[MAX1];

	//1.定范�?  2.设置种子，使每次都为随机值，如果不使用种子则此程�?      每次运行的值都一�?
	//time(NULL)为时间戳，每次都在变化，
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX1; i++)
	{
		arr[i] = rand() % MAX1;		//rand（）% a * b	这种情况是[0，a*b-1]范围的b的倍数
	}
	cout << "排序�?" << endl;
	cout << "正在排序�?..." << endl;
	int* temp = (int*)malloc(MAX1 * sizeof(int));
	// 计算时间间隔
	time_t starttime = clock();




	//BubbleSort(arr, MAX1);			//十万个数据排�? 20000 毫秒左右
	//BubbleSort1(arr, MAX1);			//十万个数据排�? 20000 毫秒左右
	//SlectSort(arr, MAX1);				//十万个数据排�? 4000  毫秒左右
	//InsertSort(arr, MAX1);			//十万个数据排�? 2500  毫秒左右
	//ShellSort(arr, MAX1);				//十万个数据排�? 18    毫秒左右
	//QuickSort(arr, 0, MAX1 - 1);		//十万个数据排�? 10    毫秒左右
	MergeSort(arr, 0, MAX1 - 1, temp);	//十万个数据排�? 16    毫秒左右





	long t_end = getSystemTime();
	time_t endtime = clock();
	cout << "排序�?" << endl;
	cout << "本次排序(" << MAX1 << "个数�?)花费" << endtime - starttime << "毫秒" << endl;
	free(temp);

}

//排序算法测试（打印版�?
void SortTest2()
{
	int arr[MAX2];

	//1.定范�?  2.设置种子，使每次都为随机值，如果不使用种子则此程�?      每次运行的值都一�?
	//time(NULL)为时间戳，每次都在变化，
	srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX2; i++)
	{
		arr[i] = rand() % MAX2;		//rand（）% a * b	这种情况是[0，a*b-1]范围的b的倍数
	}
	cout << "排序�?" << endl;
	print(arr, MAX2);
	time_t starttime = clock();
	int* temp = (int*)malloc(MAX2 * sizeof(int));


	//BubbleSort(arr, MAX2);	
	//BubbleSort1(arr, MAX2);
	//SlectSort(arr, MAX2);
	//InsertSort(arr, MAX2);
	//ShellSort(arr, MAX2);
	//QuickSort(arr, 0, MAX2 - 1);
	MergeSort(arr, 0, MAX2 - 1, temp);

	long t_end = getSystemTime();
	time_t endtime = clock();

	cout << "����ǰ" << endl;
	print(arr, MAX2);
	cout << "本次排序(" << MAX2 << "个数�?)花费" << endtime - starttime << "毫秒" << endl;
	free(temp);

}


int main()
{
	SortTest1();
	//SortTest2();


	//Timetest();

	return 0;
}
#include <stdio.h>
#include <time.h> 
#include <math.h>
#include <stdlib.h>
#include <string.h> 


// ��������� ����
// 1. �������������� ����������� ����������. 
// �������� ���������� ��������  ��������� ���������������� � �� ���������������� �������.
// �������� ������� ����������, ������� ���������� ���������� ��������.
// 2. ����������� ��������� ����������.
// 3. ����������� ������� ��������� ������.

void Swap(int* a, int* b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void PrintArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ShakerSort(int * arr, int len)
{
	int left = 0;
	int right = len - 1;
	int flagSwap = 1;

	while (left < right && flagSwap > 0)
	{
		flagSwap = 0;

		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Swap(&arr[i], &arr[i + 1]);
				flagSwap = 1;
			}
		}

		right--;

		for (int i = right; i > left; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				Swap(&arr[i - 1], &arr[i]);
				flagSwap = 1;
			}
		}

		left++;	
	}
}

int RecLinearSearch(int * arr, int len, int value, int i)
{
	if (i > len)
		return -1;

	else if (arr[i] == value)
			return i;		
	else 
		return RecLinearSearch(arr, len, value, i + 1);		
}

int BubbleSort(int* arr, int len)
{
	int countComparisons = 0;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			countComparisons++;
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}				
		}
	}
	return countComparisons;
}

int OptimizedBubbleSort(int* arr, int len) 
{
	int countComparisons = 0;

	for (int i = 0; i < len; i++)
	{
		int flag = 0; 

		for (int j = 0; j < len - 1 - i ; j++) //  �� ��������� �� ��� ��������������� � ���������� �������� ����� ������� (������)
		{
			countComparisons++;

			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}	
		}
		if (flag == 0) // ���� flag ��������� 0, ������ ������ ��� ������������ � ��� ������ ������ ������ ��������
			break;
	}
	
	return countComparisons;
}

void main(int argc, const char** argv){

	int arr[] = { 28, 17, 6, 89, 19, 24, 43, 75, 4, 16, 47, 96, 1, 33 };
	int len = sizeof(arr) / sizeof(int);

	// ���� 3 ���������� ������� (��� ����������� ������ ���������� � ������)
	// ��� �� ��� ������� ������������ �������
	int arr2[14]; 
	int arr3[14];
	memcpy(arr2, arr, sizeof(arr)); 
	memcpy(arr3, arr, sizeof(arr));

	PrintArray(arr, len);

	printf("\nShaker sort:\n");
	ShakerSort(arr, len);
	PrintArray(arr, len);
	
	printf("\nNumber of comparison operations with Bubble sort is %d\n", BubbleSort(arr2, len));
	PrintArray(arr2, len);

	printf("\nNumber of comparison operations with Optimized Bubble sort is %d\n", OptimizedBubbleSort(arr3, len));
	PrintArray(arr3, len);
	
	printf("\nIndex of number 89 is %d in the array:\n", RecLinearSearch(arr, len, 89, 0));
	PrintArray(arr, len);	
}



#include <stdio.h> 
#include <stdlib.h>

// Kolmakova Julia

int RecBinarySearch(int * arr, int start, int len, int value)
{
	int end = len - 1;

	int mid = (start + end) / 2;

	if (arr[mid] == value)
		return mid;

	if (start >= end)
		return -1;

	if (value < arr[mid])
		return RecBinarySearch(arr, start, mid + 1, value);
	else
		return RecBinarySearch(arr, mid + 1, len, value);

}

void PrintArray(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


/*
struct Brick
{
	int x;
	int y;
};

struct Brick brics[] = { 0,1, 1,1, 1,3, 3,2 };

int IsBrick(int x, int y)
{}


int Routs(int x, int y)
{
	if (IsBrick(x, y))
		return 0;
	else if (x == 0 || y == 0)
		return 1;
	else return Routs(x - 1, y) + Routs(x, y - 1);
}
*/

void main(int argc, const char** argv)
{
	int arr[] = { 1, 4, 6, 16, 17, 19, 24, 28, 33, 43, 47, 75, 89, 96 };
	int len = sizeof(arr) / sizeof(int);

	printf("\nIndex of number 17 is %d in the array:\n", RecBinarySearch(arr, 0, len, 17));
	PrintArray(arr, len);

	/*
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (IsBrick(i, j))
				printf("%6ñ ", '-');
			else
				printf("%6ñ ", Routs(i, j));
		}
		printf("\n");
	}
	*/
}
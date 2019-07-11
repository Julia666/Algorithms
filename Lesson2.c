#include <stdio.h>
#include <math.h>
int count = 0;

// ��������� ����
// 1. ����������� ������� �������� �� 10 ������� � �������� ��������� ��������
// 2. ����������� ������� ���������� ����� a � ������� b (�������� � �������� + �������� �������� �������)
// 3. �������� ����������� ����� �����. � ��������� ��� ������� (������� 1, ������ �� 2).
//    ������� ���������� ����� ��� ������ ���������, ������� ����� 3 ����������� � ����� 20 


void FillBinaryArray (char* a, int numDec, int *count) // ��������� ������ 0 � 1 (��������� �� �������)
{
	if (numDec > 0)
	{
		FillBinaryArray(a, numDec / 2, count);
		char tmp = numDec % 2 ? '1' : '0'; 
		a[*count] = tmp;
		*count += 1;
	}
}

char* ToBinary (int numDec) 
{
	char resBin[100]; //  �������� ������
	int count = 0; // ������ �������� � �������
	FillBinaryArray(resBin, numDec, &count);
	char *a; // ��������� �� ������ resBin
	a = resBin;
	a[count] = '\0'; // ����� ������
	return a;
}

int Power (int base, int index)
{
	if (index != 1)
		return base * Power(base, index - 1);
	else
		return base;
}

int Power2(int base, int index)
{
	if (index % 2 == 0)
		return Power2(base * base, index / 2);
	else
		return base * Power2(base * base, index / 2);

}

int CountVariants(int a, int b)
{
	if (a == b)
		count++; // count ���������� ���������� 
	if (a < b)
	{                               // ��� ����� (������)
		CountVariants(a + 1, b);
		CountVariants(a * 2, b);
	}
	return count;
}

void main(int argc, const char** argv) {

	int numDec = 112;
	printf("%d -> %s \n", numDec, ToBinary(numDec));

	int base = 18;
	int index = 23;
	printf("%d � ������� %d = %d\n", base, index, Power(base,index));
	printf("%d � ������� %d = %d\n", base, index, Power2(base, index));

	int a = 3;
	int b = 20;	
	printf("���������� %d ��������� �������������� ����� %d � ����� %d\n", CountVariants(a, b), a, b);
}

#include <stdio.h>
#include <math.h>

// ��������� ����
// 1. ���������� � ������� ������ ����� ���� �� ������� I = m / (h * h), ��� m � ����� ���� � �����������, h � ���� � ������.
// 2. �������� ��������� ���������� ������ ��������� ����������� ���������
// 3. ������ ������� �������� (�� 1 �� 150 ���) � ������� ��� ������ �� ������ ����, ����� ��� ����.
// 4. ���� �������� ���������� ���� ����� ��������� ����� (x1, y1, x2, y2). ��������� ����������, ��������� �� ���� � ������ ����� ��� ���.
// 5.* ����������� �����. ����������� ����� ���������� �����������, ���� ��� ����� ��������� ������ ������ ��������. ��������, 25 ^ 2 = 625. 
// �������� �������, ������� ������� �� ����� ��� ����������� �����, ������ ������ �����

void BMI() {

	double m = 52;
	double h = 1.68;
	double bmi;

	bmi = m / (h * h);

	printf("������ ����� ������ ���� ����� %f", bmi);
}

void QuadraticEquation() {

	double a = 4;
	double b = 6;
	double c = 15;
	double x1, x2;
	double D;

	D = b * b - 4 * a * c;

	if (D > 0) {  

		x1 = -1 * b + sqrt(D) / (2 * a);
		x2 = -1 * b - sqrt(D) / (2 * a);

		printf("X1 ����� %f , X2 ����� %f" , x1, x2);
	}
	else if (D == 0) {  
	
		x1 = -1 * b  / (2 * a);
		printf("X ����� %f", x1);
	}

	else
	{
		printf("������������ ������ 0, ��������� �� ����� ������");
	}
}

void Age() {

	int age = 0;

	printf("������� ��� �������:");

	scanf("%d", &age);

	// "���" - ������������� �� 1, ����� 11
	if (((age % 10) == 1) && ((age % 100) != 11))   
	{
		printf("\n��� ������� %d ���");
	}

	// "����" - ������������� �� 2,3,4 ����� 12,13,14
	else if ((age % 10 >= 2) && (age % 10 <= 4) && (age % 100 != 11) && (age % 100 != 12) && (age % 100 != 13) && (age % 100 != 14))
	{
		printf("\n��� ������� %d ����");
	}

	else
	{
		printf("\n��� ������� %d ���");
	}






}

int IsEven(int number) { // ����������� �������� �����
	int isEven = 0;

	if (number % 2 == 0)
	{
		isEven = 1;
	}
	return IsEven;
}

void ChessPoints() {

	struct Point
	{
		int x;
		int y;
	};

	struct Point A;
	struct Point B;

	A.x = 5;
	A.y = 4;
	B.x = 2;
	B.y = 6;
	
	// ������ ���� (x � y ������ ���� ���� ��� ������, ���� ��� ��������)

	if (IsEven(A.x) == IsEven(A.y) && IsEven(B.x) == IsEven(B.y))
	{
		printf("������ ���� ��������� � ������ ����� �� ��������� �����");
	}

	// ����� ���� (���� x ������, y ������ ���� ��������, � ��������, ���� x ��������, y �.�. ������)

	else if (IsEven(A.x) ^ IsEven(A.y) && IsEven(B.x) ^ IsEven(B.y))
	{
		printf("������ ���� ��������� � ������ ����� �� ��������� �����");
	}

	else
	{
		printf("������ ���� ��������� � ������ ������ �� ��������� �����");
	}
}

void AvtomorfNumbers() {

	for (int number = 0; number < 10000; number ++)
	{
		int digits = 0;
		int square = 0;

		while (number >= 0) // ������� ���-�� �������� � �����
		{
			number = number / 10;
			digits++;
		}

		square = number * number;

		if (((square - number) % (10 * digits)) == 0)  // ����., 625-25=600 (���� 00 � �����-�� ����� ��������.)
		{
			printf("%d ", number);
		}
	}



}

void main() {

	BMI();
	QuadraticEquation();
	Age();
	ChessPoints();
	AvtomorfNumbers();
}
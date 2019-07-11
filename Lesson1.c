#include <stdio.h>
#include <math.h>

// Колмакова Юлия
// 1. Рассчитать и вывести индекс массы тела по формуле I = m / (h * h), где m – масса тела в килограммах, h – рост в метрах.
// 2. Написать программу нахождения корней заданного квадратного уравнения
// 3. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе со словом «год», «года» или «лет».
// 4. Даны числовые координаты двух полей шахматной доски (x1, y1, x2, y2). Требуется определить, относятся ли поля к одному цвету или нет.
// 5.* Автоморфные числа. Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата. Например, 25 ^ 2 = 625. 
// Напишите функцию, которая выводит на экран все автоморфные числа, меньше десяти тысяч

void BMI() {

	double m = 52;
	double h = 1.68;
	double bmi;

	bmi = m / (h * h);

	printf("Индекс массы вашего тела равен %f", bmi);
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

		printf("X1 равен %f , X2 равен %f" , x1, x2);
	}
	else if (D == 0) {  
	
		x1 = -1 * b  / (2 * a);
		printf("X равен %f", x1);
	}

	else
	{
		printf("Дискриминант меньше 0, уравнение не имеет корней");
	}
}

void Age() {

	int age = 0;

	printf("Введите ваш возраст:");

	scanf("%d", &age);

	// "год" - заканчивается на 1, кроме 11
	if (((age % 10) == 1) && ((age % 100) != 11))   
	{
		printf("\nВаш возраст %d год");
	}

	// "года" - заканчивается на 2,3,4 кроме 12,13,14
	else if ((age % 10 >= 2) && (age % 10 <= 4) && (age % 100 != 11) && (age % 100 != 12) && (age % 100 != 13) && (age % 100 != 14))
	{
		printf("\nВаш возраст %d года");
	}

	else
	{
		printf("\nВаш возраст %d лет");
	}






}

int IsEven(int number) { // определение четности числа
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
	
	// Черные поля (x и y должны быть либо оба четные, либо оба нечетные)

	if (IsEven(A.x) == IsEven(A.y) && IsEven(B.x) == IsEven(B.y))
	{
		printf("Данные поля относятся к одному цвету на шахматной доске");
	}

	// Белые поля (если x четное, y должно быть нечетное, и наоборот, если x нечетное, y д.б. четное)

	else if (IsEven(A.x) ^ IsEven(A.y) && IsEven(B.x) ^ IsEven(B.y))
	{
		printf("Данные поля относятся к одному цвету на шахматной доске");
	}

	else
	{
		printf("Данные поля относятся к разным цветам на шахматной доске");
	}
}

void AvtomorfNumbers() {

	for (int number = 0; number < 10000; number ++)
	{
		int digits = 0;
		int square = 0;

		while (number >= 0) // считает кол-во разрядов в числе
		{
			number = number / 10;
			digits++;
		}

		square = number * number;

		if (((square - number) % (10 * digits)) == 0)  // напр., 625-25=600 (если 00 в конце-то число автоморф.)
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
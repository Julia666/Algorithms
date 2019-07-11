#include <stdio.h>
#include <math.h>
int count = 0;

// Колмакова Юлия
// 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию
// 2. Реализовать функцию возведения числа a в степень b (рекурсия и рекурсия + свойство четности степени)
// 3. Програма преобразует челое число. У программы две команды (Прибавь 1, Умножь на 2).
//    Сколько существует путей для данной программы, которые число 3 преобразуют в число 20 


void FillBinaryArray (char* a, int numDec, int *count) // заполняет массив 0 и 1 (остатками от деления)
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
	char resBin[100]; //  двоичный массив
	int count = 0; // индекс элемента в массиве
	FillBinaryArray(resBin, numDec, &count);
	char *a; // указатель на массив resBin
	a = resBin;
	a[count] = '\0'; // конец строки
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
		count++; // count глобальная переменная 
	if (a < b)
	{                               // две ветки (дерево)
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
	printf("%d в степени %d = %d\n", base, index, Power(base,index));
	printf("%d в степени %d = %d\n", base, index, Power2(base, index));

	int a = 3;
	int b = 20;	
	printf("Существует %d вариантов преобразования числа %d в число %d\n", CountVariants(a, b), a, b);
}

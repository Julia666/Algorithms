#include <stdio.h>
#include <stdlib.h>

const int OBSTACLE = -1;
const int UNVISITED = -2; не посещенная вершина
int grid[12][11]; // сетка
int len;  // длина пути, который будем в итоге собирать
int pointX[12 * 11]; // маcсивы, в которые будем собирать обратный маршрут (координаты)
int pointY[12 * 11];
int directionX[] = {1, 0, -1, 0};  // направление по x
int directionY[] = {0, 1, 0, -1};

// Инициализация сетки
void InitGrid() 
{
	for (int y=0; y<12; y++) 
	{
		for (int x=0; x<11; x++) 
		{
			grid[y][x] = UNVISITED;
		}
	}

	// Сначала препятствия ставятся вертикально, потом горизонтально 
	for (int t=6; t<=9; t++) 
	{
		grid[t][3] = OBSTACLE;
	}
	for (int t=3; t<=7; t++) 
	{
		grid[t][5] = OBSTACLE;
	}
	for (int t=7; t<=9; t++)
	 {
		grid[5][t] = OBSTACLE;
	}	
}

// Печать массива grid
void PrintGrid() 
{
	for (int y=0; y<12; y++) 
	{
		for (int x=0; x<11; x++) 
		{
			printf("%3d", grid[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

// Печать точек маршрута
void PrintPoints() 
{
	int i = 0;
	while(pointX[i] != -1 && pointY[i] != -1) 
	{
		printf("(%d %d) ", pointX[i], pointY[i]);
		i++; 
	}
	printf("\n");
}


int Lee(int startX, int startY, int endX, int endY) // алгоритм Ли
{
  int x, y, vector, dist, stop; // stop (флаг) - если уже некуда ставить цифры и конечная точка так и не достигнута
  if (startX == endX && startY == endY) 
  	return 0;
  if (grid[startY][startX] == OBSTACLE || grid[endY][endX] == OBSTACLE) 
  	return 0;
  dist = 0;
  grid[startY][startX] = dist;
  PrintGrid();
  do {
	stop = 1;
	for (y = 0; y < 12; y++) // просматриваем всё поле
	{
	  for (x = 0; x < 11; x++) 
	  {
		if (grid[y][x] == dist)  // если на поле есть число, которое соответствует текущему шагу
		{
			for (vector = 0; vector < 4; vector++) // идем во все 4 стороны от этого числа
			{
				int nextX = x + directionX[vector];
				int nextY = y + directionY[vector];
				if ( nextX >= 0 && nextX < 11 && nextY >= 0 && nextY < 12 && grid[nextY][nextX] == UNVISITED) 
				{
			  		stop = 0;
			  		grid[nextY][nextX] = (dist + 1); // и пишем число на 1 больше
				}
			}
		}
	  }
	}
	dist++;
  }
   while (!stop && grid[endY][endX] == UNVISITED);
  PrintGrid();
  
  if (grid[endY][endX] == UNVISITED) // если конечная точка так и осталась не посещенной
  	return 0;
  
  len = grid[endY][endX];
  
  if (dist < 11*12) 
  {
  	pointX[dist+1]=-1; // ограничиваем массив для распечатки на экран в ф-ции PrintPoints
  	pointY[dist+1]=-1;
  }

  x = endX;
  y = endY;

  while (dist >= 0) // собираем наш путь в обратном порядке (чтобы показать пользователю путь от начала к концу, а не наоборот)
  {
	pointX[dist] = x;
	pointY[dist] = y;
	dist--; 
	for (vector = 0; vector < 4; vector++) 
	{
	  int nextX = x + directionX[vector];
	  int nextY = y + directionY[vector];
	  if ( nextX >= 0 && nextX < 11 && nextY >= 0 && nextY < 12 && grid[nextY][nextX] == dist) 
	  {
		x = nextX;
		y = nextY;
	  }
	}
  }

  PrintPoints();
  return 1;
}

int matrixS[8][8] = {{ 0, 1, 0, 0, 0, 0, 0, 0 }, // матрица смежности
  					 { 1, 0, 1, 1, 0, 0, 1, 0 },
  					 { 0, 1, 0, 0, 1, 0, 0, 0 },
  					 { 0, 1, 0, 0, 0, 0, 0, 1 },
  					 { 0, 0, 1, 0, 0, 1, 0, 0 },
  					 { 0, 0, 0, 0, 1, 0, 0, 0 },
  					 { 0, 1, 0, 0, 0, 0, 0, 0 },
  					 { 0, 0, 0, 1, 0, 0, 0, 0 }};

int visitedVert[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void DepthTraverse(int numVer) 
{
	if (visitedVert[numVer]) return;
	visitedVert[numVer] = 1;
	printf("%d ", numVer);
	for (int i=0; i<8; i++) 
	{
		if (matrixS[numVer][i]) 
			HeightTraverse(i);
	}
}

int main(int argc, char const *argv[])
{
	InitGrid();
	int resLee = Lee(3,5,10,5);
	if (resLee) printf("Point (10,5) is reached\n");
	else printf("No way to point (10,5)\n");

	printf("\nTraverse of graph in depth: ");
	DepthTraverse(0);
	printf("\n");

	return 0;
}
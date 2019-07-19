#include <stdio.h> 
#include <stdlib.h>
#define T char
#define SIZE 100

// Kolmakova Julia

char binaryArray[SIZE]; 
int index = -1;


typedef struct Node {
	T data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct DecDoubleLinkedList {
    Node *head;
	Node *tail;
	int size;
} DoubleLinkedList;

int PushFirst(DoubleLinkedList *list, T val)
{
	Node *temp = (Node*)malloc(sizeof(Node)); // выделяем память под новый узел

	if (temp == NULL ) // если компьютер отказал в памяти
		return 0;

	temp->data = val; // в новый узел записываем значение, которое приняли
	temp->next = list->head; // меняем ссылку с Null на головную ссылку списка
	temp->prev = NULL; 

	list->head->prev = temp; 
	list->head = temp; // у списка поменялась голова, ею стал новый узел
	list->tail = temp;
	list->size++;

	return 1;
}

T PopFirst(DoubleLinkedList *list) 
{
	if (list->size == 0)  // если список пустой
		return -1;
	
	Node *temp = list->head; // ссылка на текущую голову
	T result = list->head->data;

	list->head = list->head->next; // текущая голова списка это стала не голова, а то, что было следующее за головой
	list->head->prev = NULL;
	free(temp); // очищаем память из под старой головы
	list->size--;
	return result;
}

int PushLast(DoubleLinkedList *list, T val)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL) {
		return 0;
	}
	temp->data = val;
	temp->next = NULL;
	temp->prev = list->tail;
	
	list->head = temp;
	list->tail->next = temp;
	list->tail = temp;
	list->size++;

	return 1;
}

T PopLast(DoubleLinkedList *list)
{
	if (list->size == 0)  // если список пустой
		return -1;
	
	Node *temp = list->tail;
	T result = list->tail->data;;

	list->tail = list->tail->prev;
	list->tail->next = NULL;	
	free(temp);
	list->size--;
	return result;
}

void Push (char* arr, char value)
{
	if (index < SIZE)
	{
		index++;
		arr[index] = value;
	}
	else
		printf("Stack overflow");
}

char* Pop(char* arr)
{
	if (index >= 0)
		return arr[index--];
	else
		printf("Stack is empty");	
}

void ToBinary(char* arr, int numDec)
{
	while (numDec > 0) 
	{
		Push(arr, numDec % 2 ? '1' : '0');
		numDec = numDec / 2;
	}
}


void main(int argc, const char** argv)
{
	int numDec = 53;

	ToBinary(binaryArray, numDec);
	printf("%d -> ", numDec);

	while ( index!= -1)
		printf("%c", Pop(binaryArray));

	DoubleLinkedList list;
	list.size = 0;
	list.head = NULL;
	list.tail = NULL;

	printf("%s\n", "This is double linked list");

	PushFirst(&list, 'a');
	PushFirst(&list, 'b');
	PushFirst(&list, 'c');
	PushFirst(&list, 'g');

	PushLast(&list, 'z');
	PushLast(&list, 'x');
	PushLast(&list, 'y');

	while (list.size > 0) 
		printf("%c ", PopFirst(&list));
	

	while (list.size > 0) 
		printf("%c ", PopLast(&list));

}




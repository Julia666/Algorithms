#include <stdio.h>
#include <stdlib.h>

// Kolmakova Julia

typedef struct Node
{
	int data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

// создание новой вершины 
Node* CreateNode(Node* parent, int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	return node;
}


// вставка вершины в дерево 
void InsertNode(Node **head, int value) { // ** - указатель на указатель (указывающий на первоначальный корень)
	Node *tmp = NULL;
	if (*head == NULL) {
		*head = CreateNode(NULL, value);
		return;
	}
	tmp = *head; 
	while(tmp) {  // пока указатель не пустой (не NULL)
		if (value >= tmp->data) {
			if (tmp->right) {
				tmp = tmp->right;
				continue;
			} else {
				tmp->right = CreateNode(tmp, value);
				return;
			}
		} else if (value < tmp->data) {
			if (tmp->left) {
				tmp = tmp->left;
				continue;
			} else {
				tmp->left = CreateNode(tmp, value);
				return;
			}
		} 
	}
}

// распечатка двоичного дерева в виде скобочной записи 
void PrintTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
        printf("(");

        if (root->left) 
            PrintTree(root->left);
        else 
            printf("NULL");
        printf(",");

        if (root->right) 
            PrintTree(root->right);
        else 
            printf("NULL");
        printf(")");
        }
    }
}

// обход в прямом порядке, pre-order (Корень -> Левый -> Правый) 
void PreOrderTraverse(Node *root) {
	if (root) {
		printf("%d ", root->data);
		PreOrderTraverse(root->left);
		PreOrderTraverse(root->right);
	}
}

// симметричный обход, in-order (Левый -> Корень -> Правый) 
void InOrderTraverse(Node *root) {
	if (root) {
		InOrderTraverse(root->left);
		printf("%d ", root->data);
		InOrderTraverse(root->right);
	}
}

// обход в обратном порядке, post-order (Левый -> Правый -> Корень) 
void PostOrderTraverse(Node *root) {
	if (root) {
		PostOrderTraverse(root->left);
		PostOrderTraverse(root->right);
		printf("%d ", root->data);
	}
}

// поиск по двоичному дереву
Node* Search(Node *root, int value) {
	if (root) {
		if (root->data == value) {
			return root;
		} else if (value > root->data) {
			return Search(root->right, value);
		} else if (value < root->data) {
			return Search(root->left, value);
		}
	} else {
		return NULL;
	}
}


int GetHash(char *arr, int len) {
	int sum = 0;
	for (int i=0; i<len; i++) {
		sum += (int)arr[i] * (i+1); // хеш меняется в зависимости от позиции символа (lesson6 != 6lesson)
	}
	return sum;
}


int main(int argc, char const *argv[])
{
	// создание двоичного дерева поиска из массива чисел
	int arr[] = {5,7,9,1,6,2,8,3,4,0};
	int len = sizeof(arr)/sizeof(int);
	Node *Tree = NULL;
	for (int i=0; i<len; i++) {
		InsertNode(&Tree, arr[i]);
	}
	// распечатка скобочной записью
	PrintTree(Tree);
	printf("\n");

	// обход 3мя способами

	printf("\nPre-order traverse:");
	PreOrderTraverse(Tree);

	printf("\nIn-order traverse");
	InOrderTraverse(Tree);

	printf("\nPost-order traverse");
	PostOrderTraverse(Tree);
	printf("\n");

	// поиск элемента в дереве
	int valueSearch = 4;
	Node *FindResult = Search(Tree, valueSearch);
	if (FindResult) {
		printf("The number %d is here %p\n", valueSearch,FindResult); 
	} else {
		printf("The number %d is not found\n", valueSearch);
	}

	// получение хeша
	char str[] = "lesson6";
	len = sizeof(str)/sizeof(char);
	int hash = GetHash(str, len);
	printf("Hash - %d\n", hash);

	return 0;
}
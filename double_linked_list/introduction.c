#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node* next;
	struct Node* prev;
} Node;

int	main(int argc, char **argv)
{
	Node* tail = malloc(sizeof(Node));
	if (tail == NULL)
		return (1);

	(void)argc;
	(void)argv;
	tail->x = 1;
	tail->prev = NULL;
	tail->next = malloc(sizeof(Node));
	if (tail == NULL)
		return (2);

	tail->next->x = 3;
	tail->next->prev = tail;
	tail->next->next = malloc(sizeof(Node));
	if (tail == NULL)
		return (3);

	tail->next->next->x = 7;
	tail->next->next->prev = tail->next;
	tail->next->next->next = NULL;
	Node* head = tail->next->next;
	(void)head;

	printf("First: %d\n", tail->x);
	printf("Second: %d\n", tail->next->x);
	printf("Third: %d\n", tail->next->next->x);

	return (0);
}

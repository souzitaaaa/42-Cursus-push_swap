#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int x;
	struct Node* next;
	struct Node* prev;
} Node;

void deallocate(Node** tail, Node** head)
{
	if (*tail == NULL)
		return;


	Node* curr = *tail;

	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);

	*tail = NULL;
	*head = NULL;
}

int	main(int argc, char **argv)
{
	int	i = 1;
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

	Node* curr = tail;
	while (curr != NULL)
	{
		printf("%i:\t%d\n",i, curr->x);
		curr = curr->next;
		i++;
	}

	printf("\n");

	i--;
	Node* curr2 = head;
	while (curr2 != NULL)
	{
		printf("%i:\t%d\n",i, curr2->x);
		curr2 = curr2->prev;
		i--;
	}

	deallocate(&tail, &head);

	return (0);
}

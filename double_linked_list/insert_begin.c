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

void insert_begin(Node** tail, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(1);

	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = *tail;
	if (*tail != NULL)
		(*tail)->prev = new_node;
	*tail = new_node;
}

void init(Node** tail, Node** head, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(2);

	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	*tail = new_node;
	*head = new_node;
}

int	main(int argc, char **argv)
{
	Node* tail = NULL;
	Node* head = NULL;
	int	i = 1;

	(void)argc;
	(void)argv;

	init(&tail, &head, 7);

	insert_begin(&tail, 3);
	insert_begin(&tail, 1);

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

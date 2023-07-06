#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	//value
	int	x;
	//pointer to the next value/list
	struct Node* next;
} Node;

int	main(int argc, char **argv)
{
	Node root;

	(void)argc;
	(void)argv;
	root.x = 15;
	root.next = malloc(sizeof(Node));
	root.next->x = -2;
	root.next->next = NULL;

	printf("First: %d\n", root.x);
	printf("Second: %d\n", root.next->x);
	//printf("Second: %d\n", (*root.next).x); Different way to print above

	free(root.next);
	return (0);
}

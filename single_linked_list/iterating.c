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
	root.next->next = malloc(sizeof(Node));
	root.next->next->x = 22;
	root.next->next->next = NULL;

	Node* curr = &root;
	while(curr != NULL)
	{
		printf("%d\n", curr->x);
		curr=curr->next;
	}

	free(root.next->next);
	free(root.next);
	return (0);
}

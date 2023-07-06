#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	//value
	int	x;
	//pointer to the next value/list
	struct Node* next;
} Node;

void insert_end(Node** root, int value)
{
	Node* new_node = malloc(sizeof(Node));

	if (new_node == NULL)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;

	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}

	Node* curr = *root;
	while(curr->next != NULL)
		curr=curr->next;
	curr->next = new_node;

}

void insert_begin(Node** root, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(2);

	new_node->x = value;
	new_node->next = *root;

	*root = new_node;
}

void insert_after(Node* node, int value)
{
	Node* new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		exit(3);

	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}

void deallocate(Node **root)
{
	Node* curr = *root;

	while (curr != NULL)
	{
		Node* aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Node* root = NULL;

	insert_end(&root, 2);
	insert_end(&root, 4);
	insert_end(&root, 5);

	insert_after(root->next->next, 7);
	insert_after(root->next->next->next, 13);

	Node* curr = root;
	while(curr != NULL)
	{
		printf("%d\n", curr->x);
		curr=curr->next;
	}

	deallocate(&root);
	return (0);
}

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

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;/*
	Node* root = malloc(sizeof(Node));
	if (root == NULL)
		exit(2);

	root->x = 15;
	root->next = NULL;*/
	Node* root = NULL;

	insert_end(&root, -2);
	insert_end(&root, 11);

	Node* curr = root;
	while(curr != NULL)
	{
		printf("%d\n", curr->x);
		curr=curr->next;
	}

	return (0);
}

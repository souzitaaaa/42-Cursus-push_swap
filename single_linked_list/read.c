#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void serialize(Node* root)
{
	FILE* file = fopen("list.txt", "w");
	if (file == NULL)
		exit (1);

	Node* curr = root;
	while(curr != NULL)
	{
		fprintf(file, "%d, ", curr->x);
		curr = curr->next;
	}
	fclose(file);
}

void deserialize(Node** root)
{
	FILE* file = fopen("list.txt", "r");
	if (file == NULL)
		exit (2);

	int value;

	while (fscanf(file, "%d, ", &value) > 0)
		insert_end(root, value);
	fclose(file);

}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Node* root = NULL;
	//Node* root2 = NULL;
	int i = 1;
/*
	insert_end(&root, -2);
	insert_end(&root, 11);
	insert_end(&root, 22);
	serialize(root);*/
	deserialize(&root);

	Node* curr = root;
	while(curr != NULL)
	{
		printf("%i:\t%d\n", i, curr->x);
		curr = curr->next;
		i++;
	}

	deallocate(&root);
	//deallocate(&root2);
	return (0);
}

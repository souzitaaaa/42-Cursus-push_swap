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

void insert_sorted(Node** root, int value)
{
	if (*root == NULL || /*(*root)->x*/(**root).x >= value)
	{
		insert_begin(root, value);
		return;
	}

	Node* curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x >= value)
		{
			insert_after(curr, value);
			return;
			//or break; so it does the insert_after outside the while
		}
		curr = curr->next;
	}

	insert_after(curr, value);

}

void remove_element(Node **root, int value)
{
	if (*root == NULL)
		return;

	if ((*root)->x == value)
	{
		Node* to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
	}

	Node *curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			Node* to_remove = curr->next;
			curr->next = curr->next->next;
			free(to_remove);
		}
		curr = curr->next;
	}

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
	int	i = 1;


	insert_end(&root, 2);
	insert_end(&root, 4);
	insert_end(&root, 5);

	insert_sorted(&root, 9);

	insert_after(root->next->next, 7);
	insert_after(root->next, 13);

	remove_element(&root, 4);

	Node* curr = root;
	while(curr != NULL)
	{
		printf("%i:\t%d\n",i, curr->x);
		curr=curr->next;
		i++;
	}

	deallocate(&root);
	return (0);
}

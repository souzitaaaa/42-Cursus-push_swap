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

void reverse(Node** root)
{
	Node* prev = NULL;
	Node* curr = *root;

	while(curr != NULL)
	{
		Node* next = curr->next;

		curr->next = prev;

		prev = curr;
		curr = next;
	}

	*root = prev;
}

int has_loops(Node* node)
{
	Node* slow = node;
	Node* fast = node;

	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			return 1;
	}
	return (0);
}

int count(Node* node)
{
	Node* curr = node;
	int c = 0;

	while (curr != NULL)
	{
		c++;
		curr = curr->next;
	}
	return (c);
}

int count_recursive(Node* node)
{
	if (node == NULL)
		return (0);

	return (1 + count_recursive(node->next));
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


	insert_end(&root, 1);
	insert_end(&root, 1);
	insert_end(&root, 3);
	insert_end(&root, 6);
	insert_end(&root, 7);

	//root->next->next->next->next->next = root->next;

	if (has_loops(root) == 1)
	{
		printf("Linked list has as a loop\n");
		return (1);
	}

	Node* curr = root;
	//printf("After reverse:\n");
	while(curr != NULL)
	{
		printf("%i:\t%d\n",i, curr->x);
		curr=curr->next;
		i++;
	}

	printf("Number of Elements: %d\n", count_recursive(root));

	/*reverse(&root);

	Node* curr2 = root;
	printf("Before reverse:\n");
	while(curr2 != NULL)
	{
		printf("%i:\t%d\n",i, curr2->x);
		curr2=curr2->next;
		i++;
	}
	*/
	deallocate(&root);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:54:30 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/19 17:11:46 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_end(t_node **stack, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		error_stacks(stack, "m");
	curr = *stack;
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	insert_begin(t_node **stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		error_stacks(stack, "m");
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

void	remove_help(t_node *curr, int value, t_node *to_remove)
{
	while (curr->next != NULL)
	{
		if (curr->next->value == value)
		{
			to_remove = curr->next;
			if (curr->next->next == NULL)
			{
				curr->next = NULL;
				free(to_remove);
				return ;
			}
			else
				curr->next = curr->next->next;
			free(to_remove);
		}
		curr = curr->next;
	}
}

void	remove_element(t_node **stack, int value)
{
	t_node	*to_remove;
	t_node	*curr;

	to_remove = NULL;
	curr = *stack;
	if (*stack == NULL)
		return ;
	if ((*stack)->value == value)
	{
		to_remove = *stack;
		*stack = (*stack)->next;
		free(to_remove);
		return ;
	}
	remove_help(curr, value, to_remove);
}

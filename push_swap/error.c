/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:56:44 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/23 16:01:25 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_stacks(t_node **stack, char *err)
{
	if (err[0] == 'm')
	{
		ft_printf("Error\n");
		deallocate_one(stack);
		exit(EXIT_FAILURE);
	}
	if (err[0] == 'd')
	{
		ft_printf("Error\n");
		deallocate_one(stack);
		exit(EXIT_FAILURE);
	}
	if (err[0] == 'l')
	{
		ft_printf("Error\n");
		deallocate_one(stack);
		exit(EXIT_FAILURE);
	}
	if (err[0] == 'a')
	{
		ft_printf("Error\n");
		deallocate_one(stack);
		exit(EXIT_FAILURE);
	}
}

void	error(char *err)
{
	if (err[0] == 'n')
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	deallocate(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	t_node	*aux_a;
	t_node	*aux_b;

	curr_a = *stack_a;
	while (curr_a != NULL)
	{
		aux_a = curr_a;
		curr_a = curr_a->next;
		free(aux_a);
	}
	*stack_a = NULL;
	curr_b = *stack_b;
	while (curr_b != NULL)
	{
		aux_b = curr_b;
		curr_b = curr_b->next;
		free(aux_b);
	}
	*stack_b = NULL;
}

void	deallocate_one(t_node **stack)
{
	t_node	*curr;
	t_node	*aux;

	curr = *stack;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*stack = NULL;
}

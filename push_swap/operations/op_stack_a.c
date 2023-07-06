/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:24 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/23 16:00:03 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*curr;
	int		swap;

	if (*stack_a == NULL)
		return ;
	curr = *stack_a;
	swap = curr->value;
	curr->value = curr->next->value;
	curr->next->value = swap;
	*stack_a = curr;
	ft_printf("sa\n");
}

void	ra(t_node **stack_a)
{
	if (*stack_a == NULL)
		return ;
	insert_end(stack_a, (*stack_a)->value);
	remove_element(stack_a, (*stack_a)->value);
	ft_printf("ra\n");
}

void	rra(t_node **stack_a)
{
	t_node	*aux;
	int		x;

	x = 0;
	if (*stack_a == NULL)
		return ;
	aux = *stack_a;
	while (aux->next != NULL)
		aux = aux->next;
	x = aux->value;
	remove_element(stack_a, x);
	insert_begin(stack_a, x);
	ft_printf("rra\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	int		x;

	x = 0;
	if (*stack_b == NULL)
		return ;
	x = (*stack_b)->value;
	insert_begin(stack_a, x);
	remove_element(stack_b, x);
	ft_printf("pa\n");
}

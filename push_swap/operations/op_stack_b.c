/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:30:05 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/23 16:00:13 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_node **stack_b)
{
	t_node	*curr;
	int		swap;

	if (*stack_b == NULL)
		return ;
	curr = *stack_b;
	swap = curr->value;
	curr->value = curr->next->value;
	curr->next->value = swap;
	ft_printf("sb\n");
}

void	rb(t_node **stack_b)
{
	if (*stack_b == NULL)
		return ;
	insert_end(stack_b, (*stack_b)->value);
	remove_element(stack_b, (*stack_b)->value);
	ft_printf("rb\n");
}

void	rrb(t_node **stack_b)
{
	t_node	*aux;
	int		x;

	x = 0;
	if (*stack_b == NULL)
		return ;
	aux = *stack_b;
	while (aux->next != NULL)
		aux = aux->next;
	x = aux->value;
	remove_element(stack_b, x);
	insert_begin(stack_b, x);
	ft_printf("rrb\n");
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	int		x;

	x = 0;
	if (*stack_a == NULL)
		return ;
	x = (*stack_a)->value;
	insert_begin(stack_b, x);
	remove_element(stack_a, x);
	ft_printf("pb\n");
}

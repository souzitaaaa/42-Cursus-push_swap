/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:21:09 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/23 15:59:40 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_node **stack_a, t_node **stack_b)
{
	if (*stack_a == NULL)
		return ;
	insert_end(stack_a, (*stack_a)->value);
	remove_element(stack_a, (*stack_a)->value);
	if (*stack_b == NULL)
		return ;
	insert_end(stack_b, (*stack_b)->value);
	remove_element(stack_b, (*stack_b)->value);
	ft_printf("rr\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
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
	if (*stack_b == NULL)
		return ;
	aux = *stack_b;
	while (aux->next != NULL)
		aux = aux->next;
	x = aux->value;
	remove_element(stack_b, x);
	insert_begin(stack_b, x);
	ft_printf("rrr\n");
}

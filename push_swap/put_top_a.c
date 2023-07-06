/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:45:37 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 14:25:18 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_both_two(t_node *aux, t_node **stack_a, t_node **stack_b)
{
	int		i;

	i = 0;
	if ((ft_strcmp(aux->op_type_a, "rr")
			&& ft_strcmp(aux->op_type_b, "rr")) == 0)
	{
		while (i < aux->n_both)
		{
			rrr(stack_a, stack_b);
			i++;
		}
	}
	else if ((ft_strcmp(aux->op_type_a, "r")
			&& ft_strcmp(aux->op_type_b, "r")) == 0)
	{
		while (i < aux->n_both)
		{
			rr(stack_a, stack_b);
			i++;
		}
	}
}

void	check_b_two(t_node *aux, t_node **stack_b, int number)
{
	if (ft_strcmp(aux->op_type_b, "rr") == 0)
	{
		while (get_first(stack_b) != number)
			rrb(stack_b);
	}
	else
	{
		while (get_first(stack_b) != number)
			rb(stack_b);
	}
}

void	check_a_two(t_node *aux, t_node **stack_a, int closer)
{
	if (ft_strcmp(aux->op_type_a, "rr") == 0)
	{
		while (get_first(stack_a) != closer)
			rra(stack_a);
	}
	else
	{
		while (get_first(stack_a) != closer)
			ra(stack_a);
	}
}

void	put_top_a(int number, int closer, t_node **stack_b, t_node **stack_a)
{
	t_node	*aux;
	int		i;
	int		times_a;
	int		times_b;

	i = 0;
	times_a = 0;
	times_b = 0;
	aux = *stack_b;
	while (aux->value != number && aux != NULL)
		aux = aux->next;
	times_a = aux->n_op_a;
	times_b = aux->n_op_b;
	check_both_two(aux, stack_a, stack_b);
	check_b_two(aux, stack_b, number);
	check_a_two(aux, stack_a, closer);
}

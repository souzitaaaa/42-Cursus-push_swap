/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_top_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:45:37 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 14:25:30 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_both(t_node *aux, t_node **stack_a, t_node **stack_b)
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

void	check_a(t_node *aux, t_node **stack_a, int number)
{
	if (ft_strcmp(aux->op_type_a, "rr") == 0)
	{
		while (get_first(stack_a) != number)
			rra(stack_a);
	}
	else
	{
		while (get_first(stack_a) != number)
			ra(stack_a);
	}
}

void	check_b(t_node *aux, t_node **stack_b, int closer)
{
	if (ft_strcmp(aux->op_type_b, "rr") == 0)
	{
		while (get_first(stack_b) != closer)
			rrb(stack_b);
	}
	else
	{
		while (get_first(stack_b) != closer)
			rb(stack_b);
	}
}

void	put_top_b(int number, int closer, t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	int		i;
	int		times_a;
	int		times_b;

	i = 0;
	times_a = 0;
	times_b = 0;
	aux = *stack_a;
	while (aux->value != number && aux != NULL)
		aux = aux->next;
	times_a = aux->n_op_a;
	times_b = aux->n_op_b;
	check_both(aux, stack_a, stack_b);
	check_a(aux, stack_a, number);
	check_b(aux, stack_b, closer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:51:51 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/19 16:24:42 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_out(t_node *aux)
{
	int		out;

	out = 0;
	if (aux->n_both != 0)
	{
		if (aux->n_op_a > aux->n_op_b)
			out = aux->n_both + (aux->n_op_a - aux->n_op_b);
		else if (aux->n_op_a < aux->n_op_b)
			out = aux->n_both + (aux->n_op_b - aux->n_op_a);
		else
			out = aux->n_both;
	}
	else
		out = aux->n_op_a + aux->n_op_b;
	return (out);
}

int	get_total_op(t_node *aux)
{
	int		total_op;

	total_op = 0;
	if (aux->n_both != 0)
	{
		if (aux->n_op_a > aux->n_op_b)
			total_op = aux->n_both + (aux->n_op_a - aux->n_op_b);
		else if (aux->n_op_a < aux->n_op_b)
			total_op = aux->n_both + (aux->n_op_b - aux->n_op_a);
		else
			total_op = aux->n_both;
	}
	else
		total_op = aux->n_op_a + aux->n_op_b;
	return (total_op);
}

int	get_number(t_node **stack)
{
	t_node	*aux;
	int		number;
	int		total_op;
	int		out;

	number = 0;
	total_op = 0;
	out = 0;
	aux = *stack;
	number = aux->value;
	out = get_out(aux);
	aux = aux->next;
	while (aux)
	{
		total_op = get_total_op(aux);
		if (out > total_op)
		{
			number = aux->value;
			out = total_op;
		}
		aux = aux->next;
	}
	return (number);
}

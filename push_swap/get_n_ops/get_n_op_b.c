/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_op_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:16:25 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 14:22:23 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_n_op_b(t_node **stack_b, t_node **stack_a, t_values values)
{
	t_node	*aux;

	aux = *stack_b;
	while (aux)
	{
		aux->n_op_b = count_op_b_two(&aux, stack_b);
		aux->n_op_a = count_op_a_two(aux, stack_a, values);
		if (ft_strcmp(aux->op_type_b, aux->op_type_a) == 0)
			aux->n_both = count_both(aux);
		else
			aux->n_both = 0;
		aux = aux->next;
	}
}

int	count_both(t_node *aux)
{
	if (aux->n_op_a > (aux->n_op_b))
	{
		if (aux->n_op_a == 0 || (aux->n_op_b == 0))
			return (0);
		else
			return (aux->n_op_b);
	}
	else if (aux->n_op_a < aux->n_op_b)
	{
		if (aux->n_op_a == 0 || (aux->n_op_b == 0))
			return (0);
		else
			return (aux->n_op_a);
	}
	else if (aux->n_op_a == aux->n_op_b)
		return (aux->n_op_a);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:45:02 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/19 13:59:37 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_op_b(t_node *aux, t_node **stack_b, t_values values)
{
	int		closer;

	closer = 0;
	closer = get_closer_b(aux->value, stack_b, values);
	if (ft_listsize(stack_b) / 2 >= get_index(closer, stack_b))
	{
		aux->op_type_b = "r";
		return (get_index(closer, stack_b) - 1);
	}
	else if (ft_listsize(stack_b) / 2 < get_index(closer, stack_b))
	{
		aux->op_type_b = "rr";
		return (ft_listsize(stack_b) - get_index(closer, stack_b) + 1);
	}
	else
		return ('\0');
}

int	count_op_a(t_node **aux, t_node **stack)
{
	if (ft_listsize(stack) / 2 >= get_index((*aux)->value, stack))
	{
		(*aux)->op_type_a = "r";
		return (get_index((*aux)->value, stack) - 1);
	}
	else if (ft_listsize(stack) / 2 < get_index((*aux)->value, stack))
	{
		(*aux)->op_type_a = "rr";
		return (ft_listsize(stack) - get_index((*aux)->value, stack) + 1);
	}
	else
		return ('\0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_op_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:16:25 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 14:23:18 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_n_op_a(t_node **stack_a, t_node **stack_b, t_values values)
{
	t_node	*aux;

	aux = *stack_a;
	while (aux)
	{
		aux->n_op_a = count_op_a(&aux, stack_a);
		aux->n_op_b = count_op_b(aux, stack_b, values);
		if (ft_strcmp(aux->op_type_a, aux->op_type_b) == 0)
			aux->n_both = count_both(aux);
		else
			aux->n_both = 0;
		aux = aux->next;
	}
}

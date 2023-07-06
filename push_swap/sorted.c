/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:17:20 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 15:26:35 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_node **stack_a)
{
	t_node	*aux;

	aux = *stack_a;
	while (aux->next != NULL)
	{
		if (aux->value < aux->next->value)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}

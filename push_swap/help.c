/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:09:46 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/23 16:40:00 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lower(t_node **stack)
{
	int		x;
	t_node	*aux;

	x = 0;
	if (stack == NULL)
		return ('\0');
	aux = *stack;
	x = aux->value;
	while (aux != NULL)
	{
		if (x > aux->value)
			x = aux->value;
		aux = aux->next;
	}
	return (x);
}

int	get_bigger(t_node **stack)
{
	int		x;
	t_node	*aux;

	x = 0;
	if (stack == NULL)
		return ('\0');
	aux = *stack;
	x = aux->value;
	while (aux != NULL)
	{
		if (x < aux->value)
			x = aux->value;
		aux = aux->next;
	}
	return (x);
}

int	ft_listsize(t_node **stack)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = *stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int	get_index(int value, t_node **stack)
{
	t_node	*aux;
	int		index;

	index = 1;
	aux = *stack;
	while (aux)
	{
		if (value == aux->value)
			return (index);
		index++;
		aux = aux->next;
	}
	return ('\0');
}

int	get_first(t_node **stack)
{
	int	x;

	x = 0;
	x = (*stack)->value;
	return (x);
}

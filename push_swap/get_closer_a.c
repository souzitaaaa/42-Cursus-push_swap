/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closer_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:28:13 by dinoguei          #+#    #+#             */
/*   Updated: 2023/06/19 17:55:25 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_a(t_node **stack, t_node *aux, t_values values, int value)
{
	while (value > values.lower_a)
	{
		value -= 1;
		aux = *stack;
		while (aux)
		{
			if (value == aux->value)
				return (aux->value);
			else
				aux = aux->next;
		}
	}
	return ('\0');
}

int	second_a(t_node **stack, t_node *aux, t_values values, int value)
{
	while (value < values.bigger_a)
	{
		value += 1;
		aux = *stack;
		while (aux)
		{
			if (value == aux->value)
				return (aux->value);
			else
				aux = aux->next;
		}
	}
	return ('\0');
}

int	third_a(t_node **stack, t_node *aux, t_values values, int value)
{
	int		temp;

	temp = value;
	while (value < values.bigger_a || temp > values.lower_a)
	{
		value += 1;
		temp -= 1;
		aux = *stack;
		while (aux)
		{
			if (value == aux->value)
				return (aux->value);
			else if (temp == aux->value)
				return (aux->value);
			else
				aux = aux->next;
		}
	}
	return ('\0');
}

int	get_closer_a(int value, t_node **stack, t_values values)
{
	t_node	*aux;
	int		out;

	out = 0;
	aux = *stack;
	if (value > values.bigger_a)
	{
		return (get_lower(stack));
	}
	else if (value < values.lower_a)
	{
		out = second_a(stack, aux, values, value);
		return (out);
	}
	else
	{
		out = third_a(stack, aux, values, value);
		return (out);
	}
	return ('\0');
}

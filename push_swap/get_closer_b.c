/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closer_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:50:12 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 14:34:02 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_b(t_node **stack, t_node *aux, t_values values, int value)
{
	while (value > values.lower_b)
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

int	second_b(t_node **stack, t_node *aux, t_values values, int value)
{
	while (value < values.bigger_b)
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

int	third_b(t_node **stack, t_node *aux, t_values values, int value)
{
	int		temp;

	temp = value;
	while (value < values.bigger_b || temp > values.lower_b)
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

int	get_closer_b(int value, t_node **stack, t_values values)
{
	t_node	*aux;
	int		out;

	out = 0;
	aux = *stack;
	if (value > values.bigger_b)
	{
		out = first_b(stack, aux, values, value);
		return (out);
	}
	else if (value < values.lower_b)
	{
		out = second_b(stack, aux, values, value);
		return (out);
	}
	else
	{
		out = third_b(stack, aux, values, value);
		return (out);
	}
	return ('\0');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:40:44 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/26 18:13:48 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	first_push(t_node **stack_a, t_node **stack_b)
{
	if (ft_listsize(stack_a) > 3)
	{
		pb (stack_a, stack_b);
		if (ft_listsize(stack_a) >= 4)
			pb (stack_a, stack_b);
	}
}

void	lower_top(t_node **stack_a, t_values values)
{
	if (get_index(values.lower_a, stack_a) > ft_listsize(stack_a) / 2)
	{
		while (get_first(stack_a) != values.lower_a)
		{
			rra(stack_a);
		}
	}
	else if (get_index(values.lower_a, stack_a) <= ft_listsize(stack_a) / 2)
	{
		while (get_first(stack_a) != values.lower_a)
		{
			ra(stack_a);
		}
	}
}

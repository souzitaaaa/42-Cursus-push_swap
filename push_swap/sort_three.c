/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:27:08 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/17 16:43:26 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a, t_node **stack_b)
{
	(void)stack_b;
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
		{
			if ((*stack_a)->next->value < (*stack_a)->next->next->value)
				ra(stack_a);
			else
			{
				ra(stack_a);
				sa(stack_a);
			}
		}
		else
			sa(stack_a);
	}
	else if ((*stack_a)->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->value > (*stack_a)->next->next->value)
		rra(stack_a);
}

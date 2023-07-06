/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:39:39 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/17 16:58:57 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a, t_node **stack_b)
{
	(void)stack_b;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

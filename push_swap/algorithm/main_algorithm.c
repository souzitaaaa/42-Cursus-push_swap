/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:39:43 by dinoguei          #+#    #+#             */
/*   Updated: 2023/06/19 16:57:15 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algorithm(t_node **stack_a, t_node **stack_b)
{
	t_values	values;
	int			closer;
	int			number;
	int			number_b;
	int			closer_b;

	closer = 0;
	number = 0;
	number_b = 0;
	closer_b = 0;
	first_push(stack_a, stack_b);
	values.lower_a = get_lower(stack_a);
	values.lower_b = get_lower(stack_b);
	values.bigger_a = get_bigger(stack_a);
	values.bigger_b = get_bigger(stack_b);
	from_a_to_b(stack_a, stack_b, &values);
	sort_three(stack_a, stack_b);
	from_b_to_a(stack_b, stack_a, &values);
	lower_top(stack_a, values);
}

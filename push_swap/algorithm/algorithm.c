/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:07:13 by dinoguei          #+#    #+#             */
/*   Updated: 2023/06/19 17:56:18 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
void print_jenny(t_node **stack_a)
{
	t_node *aux = *stack_a;

	while (aux != NULL)
	{
		printf("--------------------------------\n");
		printf(COLOR_BOLD "Number: %i\n" COLOR_OFF, aux->value);
		printf("Op_A: %i\n", aux->n_op_a);
		printf("Op_B: %i\n", aux->n_op_b);
		printf("Op_Both: %i\n", aux->n_both);
		printf("Type rotation A: %s\n", aux->op_type_a);
		printf("Type rotation B: %s\n", aux->op_type_b);
		printf("--------------------------------\n");
		aux = aux->next;
	}
}
*/

void	from_a_to_b(t_node **stack_a, t_node **stack_b, t_values *values)
{
	while (ft_listsize(stack_a) > 3)
	{
		get_n_op_a(stack_a, stack_b, *values);
		put_top_b(get_number(stack_a),
			get_closer_b(get_number(stack_a), stack_b, *values),
			stack_a, stack_b);
		pb(stack_a, stack_b);
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
		values->lower_a = get_lower(stack_a);
		values->lower_b = get_lower(stack_b);
		values->bigger_a = get_bigger(stack_a);
		values->bigger_b = get_bigger(stack_b);
	}
}

void	from_b_to_a(t_node **stack_b, t_node **stack_a, t_values *values)
{
	while (ft_listsize(stack_b) > 0)
	{
		get_n_op_b(stack_b, stack_a, *values);
		put_top_a(get_number(stack_b),
			get_closer_a(get_number(stack_b), stack_a, *values),
			stack_b, stack_a);
		pa(stack_a, stack_b);
		if (stack_a != NULL)
		{
			values->lower_a = get_lower(stack_a);
			values->bigger_a = get_bigger(stack_a);
		}
		if (ft_listsize(stack_b) > 0)
		{
			values->lower_b = get_lower(stack_b);
			values->bigger_b = get_bigger(stack_b);
		}
		if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value != values->bigger_a)
			sa(stack_a);
	}
}

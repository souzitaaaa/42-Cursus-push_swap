/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:02:14 by dinoguei          #+#    #+#             */
/*   Updated: 2023/07/05 13:03:32 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	print_stacks(t_node **stack_a, t_node **stack_b)
{
	t_node	*curr_a;
	t_node	*curr_b;
	int		i;

	curr_a = *stack_a;
	curr_b = *stack_b;
	i = 1;
	printf("      Stack A\n");
	while(curr_a != NULL)
	{
		printf("%i:\t%d\n", i, curr_a->value);
		curr_a=curr_a->next;
		i++;
	}
	i = 1;
	printf("      Stack B\n");
	while(curr_b != NULL)
	{
		printf("%i:\t%d\n", i, curr_b->value);
		curr_b=curr_b->next;
		i++;
	}
}*/

int	checkint(char *nb)
{
	int		i;

	i = 0;
	if (nb[i] == '-' && nb[i + 1] != '\0')
		i++;
	else if (nb[i] == '-' && nb[i + 1] == '\0')
		return (1);
	while (nb[i] != '\0')
	{
		if (ft_isdigit(nb[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	checkdups(int number, t_node **stack)
{
	t_node	*aux;

	aux = *stack;
	while (aux != NULL)
	{
		if (aux->value == number)
			return (1);
		else
			aux = aux->next;
	}
	return (0);
}

int	checks(char *nb, t_node **stack)
{
	long int	number;
	int			out;

	if (checkint(nb))
		error_stacks(stack, "a");
	number = ft_long_atoi(nb);
	if (number > INT_MAX || number < INT_MIN)
		error_stacks(stack, "l");
	out = number;
	if (checkdups(out, stack))
		error_stacks(stack, "d");
	return (out);
}

void	put_in_list(int size2, t_node **stack, char **argv)
{
	int		i;

	i = 1;
	while (size2 > 0)
	{
		insert_end(stack, checks(argv[i], stack));
		size2--;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		size2;

	if (!(argc < 1))
	{
		stack_a = NULL;
		stack_b = NULL;
		size = argc - 1;
		size2 = size;
		put_in_list(size2, &stack_a, argv);
		if (size == 2)
			sort_two(&stack_a, &stack_b);
		else if (size == 3 && sorted(&stack_a) == 0)
			sort_three(&stack_a, &stack_b);
		else if (size > 3 && sorted(&stack_a) == 0)
			algorithm(&stack_a, &stack_b);
		deallocate(&stack_a, &stack_b);
	}
	else
		error("n");
}

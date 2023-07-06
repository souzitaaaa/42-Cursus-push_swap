/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:54:20 by dinoguei          #+#    #+#             */
/*   Updated: 2023/05/22 15:19:59 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <stdbool.h>
# include "libft/include/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				n_op_a;
	int				n_op_b;
	int				n_both;
	int				n_total;
	char			*op_type_a;
	char			*op_type_b;
	struct s_node	*next;
}	t_node;

typedef struct s_values
{
	int		lower_a;
	int		bigger_a;
	int		lower_b;
	int		bigger_b;
}	t_values;

/*
inserts.c
*/
void	insert_end(t_node **stack, int value);
void	insert_begin(t_node **stack, int value);
void	remove_element(t_node **stack, int value);
/*
operations
*/
void	sa(t_node **stack_a);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	sb(t_node **stack_b);
void	rb(t_node **stack_b);
void	rrb(t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
/*
algorithms
*/
void	sort_two(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a, t_node **stack_b);
/*
get_n_op_a.c
*/
void	get_n_op_a(t_node **stack_a, t_node **stack_b, t_values values);
/*
count_ops_a.c
*/
int		count_op_a(t_node **aux, t_node **stack);
int		count_op_b(t_node *aux, t_node **stack_b, t_values values);
/*
count_ops_b.c
*/
int		count_op_b_two(t_node **aux, t_node **stack);
int		count_op_a_two(t_node *aux, t_node **stack_a, t_values values);
/*
get_n_op_b.c
*/
void	get_n_op_b(t_node **stack_a, t_node **stack_b, t_values values);
/*
get_number.c
*/
int		get_number(t_node **stack);
/*
help.c
*/
int		get_lower(t_node **stack);
int		get_bigger(t_node **stack);
int		ft_listsize(t_node **stack);
int		get_index(int value, t_node **stack);
int		get_first(t_node **stack);
/*
error.c
*/
void	error(char *err);
void	error_stacks(t_node **stack, char *err);
void	deallocate_one(t_node **stack);
void	deallocate(t_node **stack_a, t_node **stack_b);
/*
main.c
*/
void	print_stacks(t_node **stack_a, t_node **stack_b);
void	algorithm(t_node **stack_a, t_node **stack_b);
void	put_in_list(int size2, t_node **stack, char **argv);
/*
put_top_b.c
*/
void	put_top_b(int number, int closer, t_node **stack_a, t_node **stack_b);
void	check_b(t_node *aux, t_node **stack_b, int closer);
void	check_a(t_node *aux, t_node **stack_a, int number);
void	check_both(t_node *aux, t_node **stack_a, t_node **stack_b);
/*
put_top_a.c
*/
void	put_top_a(int number, int closer, t_node **stack_b, t_node **stack_a);
/*
get_closer_b.c
*/
int		get_closer_b(int value, t_node **stack_b, t_values values);
/*
get_closer_a.c
*/
int		get_closer_a(int value, t_node **stack, t_values values);

void	first_push(t_node **stack_a, t_node **stack_b);
void	from_a_to_b(t_node **stack_a, t_node **stack_b, t_values *values);
void	lower_top(t_node **stack_a, t_values values);
void	from_b_to_a(t_node **stack_b, t_node **stack_a, t_values *values);
int		count_both(t_node *aux);
int		sorted(t_node **stack_a);

#endif

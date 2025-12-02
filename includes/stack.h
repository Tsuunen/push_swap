/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:49 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/02 14:31:24 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int		*stack;
	size_t	size;
	char	name;
}	t_stack;

typedef struct s_best
{
	int	index;
	int	steps_to_top;
	int	steps_to_place;
	int	dir_top;
	int	dir_place;
	int	nbr_steps;
}	t_best;

typedef struct s_lis
{
	int	start;
	int size;
}	t_lis;

int		swap(t_stack s);
int		push(t_stack *from, t_stack *to);
int		rotate(t_stack s);
int		rotate_reverse(t_stack s);
int		shift_reverse(t_stack s);
int		shift(t_stack s);
int		count_to_top(t_stack s, int index, int *direction);
int		count_to_place(t_stack s, int value, int *direction);
int		count_to_place_reverse(t_stack s, int value, int *direction);
int		find_best(t_stack from, t_stack to, t_best *best);
int		find_best_reverse(t_stack from, t_stack to, t_best *best);
int		sort(t_stack *a, t_stack *b);
void	print_stack(t_stack s);
int		find_max(t_stack s);
int		find_min(t_stack s);
int		find_max_reverse(t_stack s);
int		find_min_reverse(t_stack s);
int		universal_rotate(t_stack s, int direction);
void	rotate_both(t_stack a, t_stack b, int direction);
int		check_sort(t_stack s);
int		max(int a, int b);
int		min(int a, int b);
void	replace_best(t_best *best, t_best tmp, int i);
void	compute_best_nbr_steps(t_best *best);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:54:52 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/02 13:34:11 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	sort_3group(t_stack s)
{
	int	max;

	max = find_max(s);
	if (max == 0)
		universal_rotate(s, 0);
	else if (max == 1)
		universal_rotate(s, 1);
	if (s.stack[0] > s.stack[1])
		swap(s);
	return (0);
}

void	sort_to_b(t_stack *a, t_stack *b)
{
	int		tmp;
	t_best	best;
	int		i;

	while (a->size > 3 && !check_sort(*a))
	{
		find_best(*a, *b, &best);
		tmp = 0;
		if (best.dir_top == best.dir_place && best.steps_to_top
			&& best.steps_to_place)
		{
			while (tmp < min(best.steps_to_top, best.steps_to_place))
			{
				rotate_both(*a, *b, best.dir_top);
				tmp++;
			}
		}
		i = 0;
		while (i++ < best.steps_to_top - tmp)
			universal_rotate(*a, best.dir_top);
		i = 0;
		while (i++ < best.steps_to_place - tmp)
			universal_rotate(*b, best.dir_place);
		push(a, b);
	}
}

void	sort_to_a(t_stack *a, t_stack *b)
{
	t_best	best;
	int		tmp;
	int		i;

	while (b->size > 0)
	{
		find_best_reverse(*b, *a, &best);
		tmp = 0;
		if (best.dir_top == best.dir_place && best.steps_to_top
			&& best.steps_to_place)
		{
			while (tmp < min(best.steps_to_top, best.steps_to_place))
			{
				rotate_both(*a, *b, best.dir_top);
				tmp++;
			}
		}
		i = 0;
		while (i++ < best.steps_to_top - tmp)
			universal_rotate(*b, best.dir_top);
		i = 0;
		while (i++ < best.steps_to_place - tmp)
			universal_rotate(*a, best.dir_place);
		push(b, a);
	}
}

int	sort_2group(t_stack s)
{
	if (s.stack[0] > s.stack[1])
		swap(s);
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	if (a->size < 2)
		return (0);
	else if (a->size == 2)
		return (sort_2group(*a));
	else if (a->size == 3)
		return (sort_3group(*a));
	push(a, b);
	push(a, b);
	sort_to_b(a, b);
	if (!check_sort(*a) && a->size == 3)
		sort_3group(*a);
	sort_to_a(a, b);
	tmp = count_to_top(*a, find_min(*a), &i);
	while (tmp--)
		universal_rotate(*a, i);
	return (0);
}

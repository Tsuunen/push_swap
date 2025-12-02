/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:54:20 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/02 13:45:14 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	count_to_top(t_stack s, int index, int *direction)
{
	int	from_bot;

	from_bot = s.size - index;
	if (from_bot < index)
	{
		*direction = 1;
		return (from_bot);
	}
	*direction = 0;
	return (index);
}

int	min_handler(t_stack s, int *direction)
{
	int	min;
	int	tmp;

	min = find_min(s);
	if (min == 0)
	{
		*direction = 0;
		return (1);
	}
	if (count_to_top(s, min, direction)
		< count_to_top(s, find_min_reverse(s), direction))
		tmp = count_to_top(s, min, direction);
	else
		tmp = count_to_top(s, find_min_reverse(s), direction);
	if (*direction == 0)
		return (tmp + 1);
	return (tmp - 1);
}

int	manage_minmax(t_stack s, int value, int *direction)
{
	int	max;
	int	min;

	max = find_max(s);
	min = find_min(s);
	if (value > s.stack[max])
	{
		if (count_to_top(s, max, direction)
			< count_to_top(s, find_max_reverse(s), direction))
			return (count_to_top(s, max, direction));
		return (count_to_top(s, find_max_reverse(s), direction));
	}
	if (value < s.stack[min])
		return (min_handler(s, direction));
	return (-1);
}

int	count_to_place(t_stack s, int value, int *direction)
{
	int	tmp;
	int	min;

	if (s.size < 2)
		return (0);
	tmp = manage_minmax(s, value, direction);
	if (tmp != -1)
		return (tmp);
	tmp = 0;
	min = s.size;
	while ((size_t) tmp < s.size)
	{
		if (value >= s.stack[tmp]
			&& value <= s.stack[(tmp - 1 + s.size) % s.size])
			if (min > count_to_top(s, tmp, direction))
				min = count_to_top(s, tmp, direction);
		tmp++;
	}
	return (min);
}

int	find_best(t_stack from, t_stack to, t_best *best)
{
	size_t	i;
	t_best	tmp;

	i = 1;
	best->index = 0;
	best->steps_to_top = count_to_top(from, 0, &best->dir_top);
	best->steps_to_place = count_to_place(to, from.stack[0], &best->dir_place);
	compute_best_nbr_steps(best);
	while (i < from.size)
	{
		tmp.steps_to_top = count_to_top(from, i, &tmp.dir_top);
		tmp.steps_to_place = count_to_place(to, from.stack[i], &tmp.dir_place);
		compute_best_nbr_steps(&tmp);
		if (tmp.nbr_steps < best->nbr_steps)
			replace_best(best, tmp, i);
		i++;
	}
	return (0);
}

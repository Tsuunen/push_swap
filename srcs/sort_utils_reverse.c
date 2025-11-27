/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:34:09 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/27 16:35:02 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	manage_minmax_reverse(t_stack s, int value, int *direction)
{
	int	min;
	int	max;

	max = find_max(s);
	min = find_min(s);
	if (value < s.stack[min])
		return (count_to_top(s, min, direction));
	if (value > s.stack[max])
	{
		if (max == 0)
		{
			*direction = 0;
			return (1);
		}
		min = count_to_top(s, max, direction);
		if (*direction == 0)
			return (min + 1);
		return (min - 1);
	}
	return (-1);
}

int	count_to_place_reverse(t_stack s, int value, int *direction)
{
	int	tmp;

	if (s.size < 2)
		return (0);
	tmp = manage_minmax_reverse(s, value, direction);
	if (tmp != -1)
		return (tmp);
	tmp = 0;
	while ((size_t) tmp < s.size)
	{
		if (value <= s.stack[tmp]
			&& value >= s.stack[(tmp - 1 + s.size) % s.size])
			return (count_to_top(s, tmp, direction));
		tmp++;
	}
	return (-1);
}

int	find_best_reverse(t_stack from, t_stack to, t_best *best)
{
	size_t	i;
	int		tmp_top;
	int		tmp_place;
	int		tmp_dir_top;
	int		tmp_dir_place;

	i = 0;
	best->index = 0;
	best->steps_to_top = count_to_top(from, 0, &best->dir_top);
	best->steps_to_place = count_to_place_reverse(to, from.stack[0],
			&best->dir_place);
	while (++i < from.size)
	{
		tmp_top = count_to_top(from, i, &tmp_dir_top);
		tmp_place = count_to_place_reverse(to, from.stack[i], &tmp_dir_place);
		if (tmp_top + tmp_place < best->steps_to_top + best->steps_to_place)
		{
			best->index = i;
			best->steps_to_top = tmp_top;
			best->steps_to_place = tmp_place;
			best->dir_top = tmp_dir_top;
			best->dir_place = tmp_dir_place;
		}
	}
	return (0);
}

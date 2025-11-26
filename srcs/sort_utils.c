/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:54:20 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/26 16:58:45 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	find_min(t_stack s)
{
	size_t	i;
	int		min;

	i = 1;
	min = 0;
	while (i < s.size)
	{
		if (s.stack[i] < s.stack[min])
			min = i;
		else if (s.stack[i] == s.stack[min]
				&& s.stack[(i + 1) % s.size] > s.stack[min + 1])
				min = i;
		i++;
	}
	return (min);
}

int	find_max(t_stack s)
{
	size_t	i;
	int		max;

	i = 1;
	max = 0;
	while (i < s.size)
	{
		if (s.stack[i] > s.stack[max])
			max = i;
		else if (s.stack[i] == s.stack[max]
				&& s.stack[i - 1] < s.stack[(max - 1 + s.size)])
				max = i;
		i++;
	}
	return (max);
}

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

int	count_to_place(t_stack s, int value, int *direction)
{
	int	min;
	int	tmp;

	if (s.size < 2)
		return (0);
	tmp = find_max(s);
	min = find_min(s);
	if (value > s.stack[tmp])
		return (count_to_top(s, tmp, direction));
	if (value < s.stack[min])
	{
		if (min == 0)
		{
			*direction = 0;
			return (1);
		}
		tmp = count_to_top(s, min, direction);
		if (*direction == 0)
			return (tmp + 1);
		return (tmp - 1);
	}
	tmp = 0;
	while ((size_t) tmp < s.size)
	{
		if (value >= s.stack[tmp]
			&& value <= s.stack[(tmp - 1 + s.size) % s.size])
			return (count_to_top(s, tmp, direction));
		tmp++;
	}
	return (-1);
}

int	find_best(t_stack from, t_stack to, t_best *best)
{
	size_t	i;
	int		tmp_top;
	int		tmp_place;
	int		tmp_dir_top;
	int		tmp_dir_place;

	i = 1;
	best->index = 0;
	best->steps_to_top = count_to_top(from, 0, &best->dir_top);
	best->steps_to_place = count_to_place(to, from.stack[0], &best->dir_place);
	while (i < from.size)
	{
		tmp_top = count_to_top(from, i, &tmp_dir_top);
		tmp_place = count_to_place(to, from.stack[i], &tmp_dir_place);
		if (tmp_top + tmp_place < best->steps_to_top + best->steps_to_place)
		{
			best->index = i;
			best->steps_to_top = tmp_top;
			best->steps_to_place = tmp_place;
			best->dir_top = tmp_dir_top;
			best->dir_place = tmp_dir_place;
		}
		i++;
	}
	return (0);
}

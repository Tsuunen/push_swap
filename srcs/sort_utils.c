/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:54:20 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/26 11:08:56 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
		*direction = 0;
		return (from_bot);
	}
	*direction = 1;
	return (index);
}

int	count_to_place(t_stack s, int value, int *direction)
{
	int	max;
	int	min;
	int	tmp;

	if (s.size < 2)
		return (0);
	max = find_max(s);
	min = find_min(s);
	if (value >= s.stack[max])
		return (count_to_top(s, max, direction));
	if (value <= s.stack[min])
	{
		tmp = count_to_top(s, min, direction);
		if (*direction == 1)
			return (tmp + 1);
		return (tmp - 1);
	}
	if (value >= s.stack[0] && value <= s.stack[s.size - 1])
		return (0);
	tmp = 1;
	while ((size_t) tmp < s.size)
	{
		if (value >= s.stack[tmp] && value <= s.stack[tmp - 1])
			return (count_to_top(s, tmp, direction));
		tmp++;
	}
	return (-1);
}

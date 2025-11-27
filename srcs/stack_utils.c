/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:35:42 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/27 16:36:06 by relaforg         ###   ########.fr       */
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

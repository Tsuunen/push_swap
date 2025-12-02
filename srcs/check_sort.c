/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:07:41 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/02 14:31:10 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	check_sort(t_stack s)
{
	int		max_found;
	size_t	i;

	i = 0;
	max_found = 0;
	while (i < s.size)
	{
		if (s.stack[i] > s.stack[(i + 1) % s.size])
		{
			if (max_found)
				return (0);
			max_found = 1;
		}
		i++;
	}
	return (1);
}

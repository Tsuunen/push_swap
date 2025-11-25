/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:55:44 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/25 09:55:53 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	shift(t_stack s)
{
	size_t	i;
	int		tmp;

	i = s.size - 1;
	tmp = s.stack[i];
	while (i > 0)
	{
		s.stack[i] = s.stack[i - 1];
		i--;
	}
	return (tmp);
}

int	shift_reverse(t_stack s)
{
	size_t	i;
	int		tmp;

	i = 0;
	tmp = s.stack[i];
	while (i < s.size - 1)
	{
		s.stack[i] = s.stack[i + 1];
		i++;
	}
	return (tmp);
}

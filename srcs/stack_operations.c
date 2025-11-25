/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:21:46 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/25 09:43:34 by relaforg         ###   ########.fr       */
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

int	swap(t_stack s)
{
	int	tmp;

	if (s.size < 2)
		return (1);
	tmp = s.stack[0];
	s.stack[0] = s.stack[1];
	s.stack[1] = tmp;
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	if (!from->size)
		return (1);
	if (to->size > 0)
		to->stack[to->size] = shift(*to);
	to->stack[0] = from->stack[0];
	to->size += 1;
	shift_reverse(*from);
	from->size -= 1;
	return (0);
}

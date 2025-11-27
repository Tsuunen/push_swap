/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:54:52 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/27 15:55:11 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

int	universal_rotate(t_stack s, int direction)
{
	if (!direction)
		return (rotate(s));
	return (rotate_reverse(s));
}

int	rotate_both(t_stack a, t_stack b, int direction)
{
	if (!direction)
		ft_printf("rr\n");
	else
		ft_printf("rrr\n");
	universal_rotate(a, direction);
	return (universal_rotate(b, direction));
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	sort_3group(t_stack s)
{
	int	max;

	max = find_max(s);
	if (max == 0)
	{
		rotate(s);
		ft_printf("ra\n");
	}
	else if (max == 1)
	{
		rotate_reverse(s);
		ft_printf("rra\n");
	}
	if (s.stack[0] > s.stack[1])
	{
		swap(s);
		ft_printf("sa\n");
	}
	return (0);
}

int	sort(t_stack *a, t_stack *b)
{
	t_best	best;
	int		tmp;
	int		i;

	if (a->size < 3)
		return (0);
	else if (a->size == 3)
		return (sort_3group(*a));
	push(a, b);
	push(a, b);
	ft_printf("pb\npb\n");
	while (a->size > 3)
	{
		find_best(*a, *b, &best);
		tmp = 0;
		if (best.dir_top == best.dir_place)
			while (tmp < min(best.steps_to_top, best.steps_to_place)
				&& best.steps_to_top && best.steps_to_place)
			{
				rotate_both(*a, *b, best.dir_top);
				tmp++;
			}
		i = 0;
		while (i < best.steps_to_top - tmp)
		{
			universal_rotate(*a, best.dir_top);
			i++;
			if (!best.dir_top)
				ft_printf("ra\n");
			else
				ft_printf("rra\n");
		}
		i = 0;
		while (i < best.steps_to_place - tmp)
		{
			universal_rotate(*b, best.dir_place);
			i++;
			if (!best.dir_place)
				ft_printf("rb\n");
			else
				ft_printf("rrb\n");
		}
		push(a, b);
		ft_printf("pb\n");
	}
	sort_3group(*a);
	while (b->size > 0)
	{
		find_best_reverse(*b, *a, &best);
		tmp = 0;
		if (best.dir_top == best.dir_place)
			while (tmp < min(best.steps_to_top, best.steps_to_place)
				&& best.steps_to_top && best.steps_to_place)
			{
				rotate_both(*a, *b, best.dir_top);
				tmp++;
			}
		i = 0;
		while (i < best.steps_to_top - tmp)
		{
			universal_rotate(*b, best.dir_top);
			i++;
			if (!best.dir_top)
				ft_printf("rb\n");
			else
				ft_printf("rrb\n");
		}
		i = 0;
		while (i < best.steps_to_place - tmp)
		{
			universal_rotate(*a, best.dir_place);
			i++;
			if (!best.dir_place)
				ft_printf("ra\n");
			else
				ft_printf("rra\n");
		}
		push(b, a);
		ft_printf("pa\n");
	}
	tmp = count_to_top(*a, find_min(*a), &i);
	while (tmp)
	{
		universal_rotate(*a, i);
		if (!i)
			ft_printf("ra\n");
		else
			ft_printf("rra\n");
		tmp--;
	}
	return (0);
}

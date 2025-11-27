/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/27 16:47:37 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

static int	init_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int		i;
	char	*end;

	i = 0;
	a->size = argc - 1;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
	while (i < argc - 1)
	{
		a->stack[i] = ft_strtoi(argv[i + 1], &end);
		if (*end)
			return (1);
		i++;
	}
	return (0);
}

void	print_stack(t_stack s)
{
	size_t	i;

	i = 0;
	ft_printf("[ ");
	while (i < s.size)
	{
		ft_printf("%d", s.stack[i++]);
		if (i < s.size)
			ft_printf(", ");
	}
	ft_printf(" ]\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.stack = ft_calloc(argc - 1, sizeof(int));
	if (!a.stack)
		return (1);
	b.stack = ft_calloc(argc - 1, sizeof(int));
	if (!b.stack)
	{
		free(a.stack);
		return (1);
	}
	if (init_stacks(&a, &b, argc, argv))
	{
		free(a.stack);
		free(b.stack);
		return (2);
	}
	sort(&a, &b);
	free(a.stack);
	free(b.stack);
	return (0);
}

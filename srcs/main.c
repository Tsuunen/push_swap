/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:23:04 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/24 15:28:57 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	size_t	i;
	char	*end;

	a.stack = ft_calloc(argc - 1, sizeof(int));
	if (!a.stack)
		return (1);
	b.stack = ft_calloc(argc - 1, sizeof(int));
	if (!b.stack)
	{
		free(a.stack);
		return (1);
	}
	a.size = argc - 1;
	b.size = 0;
	i = 0;
	while ((int) i < argc)
	{
		a.stack[i] = ft_strtoi(argv[i], &end);
		if (!*end)
		{
			free(a.stack);
			free(b.stack);
			return (2);
		}
		i++;
	}
	i = 0;
	while (i < a.size)
		ft_printf("%d\n", a.stack[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:03:49 by relaforg          #+#    #+#             */
/*   Updated: 2025/11/25 09:48:14 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

#include <stddef.h>

typedef struct
{
	int	*stack;
	size_t	size;
}	t_stack;

int	swap(t_stack s);
int	push(t_stack *from, t_stack *to);
int	rotate(t_stack s);
int	rotate_reverse(t_stack s);

#endif

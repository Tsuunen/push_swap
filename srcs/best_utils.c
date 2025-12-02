/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relaforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:37:36 by relaforg          #+#    #+#             */
/*   Updated: 2025/12/02 13:43:46 by relaforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	replace_best(t_best *best, t_best tmp, int i)
{
	best->index = i;
	best->steps_to_top = tmp.steps_to_top;
	best->steps_to_place = tmp.steps_to_place;
	best->dir_top = tmp.dir_top;
	best->dir_place = tmp.dir_place;
	best->nbr_steps = tmp.nbr_steps;
}

void	compute_best_nbr_steps(t_best *best)
{
	if (best->dir_place == best->dir_top)
		best->nbr_steps = max(best->steps_to_place, best->steps_to_top);
	else
		best->nbr_steps = best->steps_to_place + best->steps_to_top;
}

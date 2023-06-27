/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:43:16 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:43:16 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Returns how many steps are needed to get into top position of the stack 
considering a given direction
*/
int	get_steps(int cur_pos, int size)
{
	int	steps;

	if (cur_pos <= size / 2 + 1)
	{
		steps = cur_pos - 1;
	}
	else
		steps = size - cur_pos + 1;
	return (steps);
}

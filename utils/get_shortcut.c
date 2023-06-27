/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortcut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:43:02 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:43:02 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verify if taking a shorcut is possible and useful. Returns the new steps.
int	get_shortcut(t_picker **src, t_picker **dst)
{
	int	newpos;

	if ((*src)->dir == TOP)
	{
		newpos = (*src)->cur_pos + (*dst)->steps;
		if (newpos > (*src)->size / 2 + 1
			&& newpos > 0
			&& newpos < (*src)->size)
		{
			return ((*src)->size - (*src)->cur_pos + 1);
		}
	}
	else if ((*src)->dir == BOT)
	{
		newpos = (*src)->cur_pos - (*dst)->steps;
		if (newpos <= (*src)->size / 2 + 1
			&& newpos > 0
			&& newpos < (*src)->size)
		{
			return ((*src)->cur_pos - 1);
		}
	}
	return (0);
}

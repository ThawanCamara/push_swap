/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_abs_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:28:42 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:28:42 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_offset_lesser(t_stack *stk, long int offset)
{
	t_stack	*lesser;
	t_stack	*tmp;
	int		limit;

	limit = 2147483647;
	tmp = stk;
	lesser = stk;
	while (tmp)
	{
		if ((long)tmp->value > offset && tmp->value <= limit)
		{
			limit = tmp->value;
			lesser = tmp;
		}
		tmp = tmp->next;
	}
	return (lesser);
}

// Call set absolute position on start.
void	set_abs_position(t_stack **stk)
{
	t_stack			*tmp;
	t_stack			*lesser;
	int				index;
	long int		offset;

	tmp = *stk;
	index = 1;
	offset = -2147483649;
	if (*stk != NULL)
	{
		while (tmp)
		{
			lesser = get_offset_lesser(*stk, offset);
			lesser->abs_pos = index;
			index++;
			offset = lesser->value;
			tmp = tmp->next;
		}
	}
}

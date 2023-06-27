/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:28:05 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:28:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_greater(t_stack *stk)
{
	t_stack	*tmp;
	int		greater;

	tmp = stk;
	greater = 1;
	while (tmp)
	{
		if (tmp->abs_pos > greater)
			greater = tmp->abs_pos;
		tmp = tmp->next;
	}
	return (greater);
}

// Greater value above a limit
int	get_greater_above(t_stack *stk, int value)
{
	t_stack	*tmp;
	int		greater;

	tmp = stk;
	greater = 1;
	while (tmp)
	{
		if (tmp->abs_pos > value && tmp->abs_pos >= greater)
			greater = tmp->abs_pos;
		tmp = tmp->next;
	}
	return (greater);
}

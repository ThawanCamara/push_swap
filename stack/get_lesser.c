/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lesser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:28:22 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:28:22 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lesser(t_stack *stk)
{
	t_stack	*tmp;
	int		lesser;

	tmp = stk;
	lesser = 2147483647;
	while (tmp)
	{
		if (tmp->abs_pos < lesser)
			lesser = tmp->abs_pos;
		tmp = tmp->next;
	}
	return (lesser);
}

// Lesser value above a limit
int	get_lesser_above(t_stack *stk, int value)
{
	t_stack	*tmp;
	int		lesser;

	tmp = stk;
	lesser = 2147483647;
	while (tmp)
	{
		if (tmp->abs_pos > value && tmp->abs_pos <= lesser)
			lesser = tmp->abs_pos;
		tmp = tmp->next;
	}
	return (lesser);
}

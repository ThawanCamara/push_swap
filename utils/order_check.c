/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:43:32 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:43:32 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	def_cmp(int a, int b, int min, int max)
{
	if (max == a && min == b)
		return (1);
	return (b > a);
}

int	order_check(t_stack *stk)
{
	t_stack	*tmp;
	int		min;
	int		max;

	min = get_lesser(stk);
	max = get_greater(stk);
	tmp = stk->next;
	if (def_cmp(stk->tail->abs_pos, stk->abs_pos, min, max) == 0)
		return (0);
	while (tmp)
	{
		if (def_cmp(tmp->prev->abs_pos, tmp->abs_pos, min, max) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

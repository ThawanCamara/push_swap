/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:40:05 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 19:59:35 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_target(t_stack **stk, int src_abs)
{
	t_stack	*tmp;
	int		target;

	tmp = stk[A];
	target = get_lesser_above(stk[A], src_abs);
	while (tmp)
	{
		if (tmp->abs_pos == target)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = stk[A];
	while (tmp)
	{
		if (tmp->abs_pos == get_lesser(stk[A]))
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (stk[A]);
}

static void	cheapest_loop(t_stack **stk, int *cheapest)
{
	t_stack	*tmp;
	int		cost;
	int		tmp_cost;

	tmp = stk[B];
	cost = 2147483647;
	tmp_cost = 2147483647;
	while (tmp)
	{
		tmp_cost = get_steps(tmp->cur_pos, stk[B]->size)
			+ get_steps(get_target(stk, tmp->abs_pos)->cur_pos, stk[A]->size);
		if (tmp_cost <= cost)
		{
			cheapest[B] = tmp->abs_pos;
			cheapest[A] = get_target(stk, tmp->abs_pos)->abs_pos;
			cost = tmp_cost;
		}
		tmp = tmp->next;
	}
}

int	*get_cheapest(t_stack **stk)
{
	int		*cheapest;

	cheapest = (int *)malloc(sizeof(int) * 2);
	cheapest[A] = stk[A]->abs_pos;
	cheapest[B] = stk[B]->abs_pos;
	cheapest_loop(stk, cheapest);
	return (cheapest);
}

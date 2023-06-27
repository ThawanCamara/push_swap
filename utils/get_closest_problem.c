/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_problem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:37:55 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:37:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_front_prob(t_stack **stk)
{
	t_stack	*tmp;

	tmp = stk[A];
	while (tmp)
	{
		if (get_magnitude(stk[A], stk))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

static t_stack	*get_rear_prob(t_stack **stk)
{
	t_stack	*tmp;

	tmp = stk[A]->tail;
	while (tmp)
	{
		if (get_magnitude(stk[A], stk))
			return (tmp);
		tmp = tmp->prev;
	}
	return (0);
}

// Returns the absolute value of the closest problem
int	get_closest_prob(t_stack **stk)
{
	t_stack		*front_prob;
	t_stack		*rear_prob;
	int			size;

	size = stk[A]->size;
	front_prob = get_front_prob(stk);
	rear_prob = get_rear_prob(stk);
	if (front_prob == NULL && rear_prob == NULL)
		return (-1);
	if (get_steps(front_prob->cur_pos, size)
		<= get_steps(rear_prob->cur_pos, size))
	{
		return (front_prob->abs_pos);
	}
	else
	{
		return (rear_prob->abs_pos);
	}
}

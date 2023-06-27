/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:26:19 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:26:19 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The first becomes the last
static t_stack	*ops_rot(t_stack *first)
{
	t_stack	*last;
	t_stack	*second;

	second = first->next;
	last = first->tail;
	second->prev = NULL;
	first->prev = last;
	last->next = first;
	first->next = NULL;
	second->size = first->size;
	second->tail = first;
	return (second);
}

void	ra(t_stack **stk)
{
	stk[A] = ops_rot(stk[A]);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stk)
{
	stk[B] = ops_rot(stk[B]);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stk)
{
	stk[A] = ops_rot(stk[A]);
	stk[B] = ops_rot(stk[B]);
	ft_putendl_fd("rr", 1);
}

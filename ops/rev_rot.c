/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:43 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:25:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The last becomes the first
static t_stack	*ops_rrot(t_stack *first)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = first->tail;
	penultimate = last->prev;
	last->prev = NULL;
	first->prev = last;
	last->next = first;
	penultimate->next = NULL;
	last->size = first->size;
	last->tail = penultimate;
	return (last);
}

void	rra(t_stack **stk)
{
	stk[A] = ops_rrot(stk[A]);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stk)
{
	stk[B] = ops_rrot(stk[B]);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stk)
{
	stk[A] = ops_rrot(stk[A]);
	stk[B] = ops_rrot(stk[B]);
	ft_putendl_fd("rrr", 1);
}

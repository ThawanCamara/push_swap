/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:26:55 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:27:09 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ops_swap(t_stack *first)
{
	t_stack	*second;
	int		tmp;

	second = first->next;
	tmp = first->init_pos;
	first->init_pos = second->init_pos;
	second->init_pos = tmp;
	second->prev = first->prev;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	first->next = second->next;
	second->next = first;
	if (first->tail != second)
		second->tail = first->tail;
	else
		second->tail = first;
	first->tail = NULL;
	second->size = first->size;
	return (second);
}

void	sa(t_stack **stk)
{
	stk[A] = ops_swap(stk[A]);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stk)
{
	stk[B] = ops_swap(stk[B]);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stk)
{
	stk[A] = ops_swap(stk[A]);
	stk[B] = ops_swap(stk[B]);
	ft_putendl_fd("ss", 1);
}

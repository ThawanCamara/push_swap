/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:25:36 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:31:07 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stk)
{
	stk[A] = push(stk[A], stk[B]->value);
	stk[A]->abs_pos = stk[B]->abs_pos;
	stk[A]->init_pos = stk[B]->abs_pos;
	stk[B] = pop(stk[B]);
	insert_init_position(stk);
	update_cur_position(stk);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stk)
{
	stk[B] = push(stk[B], stk[A]->value);
	stk[B]->abs_pos = stk[A]->abs_pos;
	stk[A] = pop(stk[A]);
	remove_init_position(stk);
	update_cur_position(stk);
	ft_putendl_fd("pb", 1);
}

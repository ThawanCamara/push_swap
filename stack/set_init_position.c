/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:29:28 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:29:28 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//value:	10 -30 22
//abs:		 2   1  3
//init:		 1   2  3
//cur:       1   2  3

//ra

//value:	-30 22 10
//abs:		 1   3  2
//init:		 2   3  1
//cur:       1   2  3


void	set_init_position(t_stack **stk)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	tmp = stk[A];
	while (tmp)
	{
		tmp->init_pos = index;
		index++;
		tmp = tmp->next;
	}
}

void	remove_init_position(t_stack **stk)
{
	t_stack	*tmp;

	tmp = stk[A];
	while (tmp)
	{
		if (tmp->init_pos == 1)
			break ;
		tmp->init_pos = tmp->init_pos - 1;
		tmp = tmp->next;
	}
}

void	insert_init_position(t_stack **stk)
{
	t_stack	*tmp;

	tmp = stk[A]->next;
	while (tmp)
	{
		if (tmp->init_pos == 1)
			break ;
		tmp->init_pos = tmp->init_pos + 1;
		tmp = tmp->next;
	}
}

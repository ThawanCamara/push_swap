/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cur_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:29:15 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:29:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Call update current position when a list changes size ou gets rearranged.
void	update_cur_position(t_stack **stk)
{
	int		index;
	t_stack	*tmp;

	index = 1;
	tmp = stk[A];
	while (tmp)
	{
		tmp->cur_pos = index;
		index++;
		tmp = tmp->next;
	}
	index = 1;
	tmp = stk[B];
	while (tmp)
	{
		tmp->cur_pos = index;
		index++;
		tmp = tmp->next;
	}
}

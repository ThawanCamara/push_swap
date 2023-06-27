/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:27:52 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:27:52 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stack(t_stack **stk)
{
	t_stack	*tmp;

	tmp = stk[A];
	while (tmp)
	{
		tmp = tmp->next;
		stk[A] = pop(stk[A]);
	}
	tmp = stk[B];
	while (tmp)
	{
		tmp = tmp->next;
		stk[B] = pop(stk[B]);
	}
}

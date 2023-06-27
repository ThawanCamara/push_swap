/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:41:04 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:41:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_mag_smaller(int mag, int rev)
{
	if (mag < 0)
		mag *= -1;
	if (rev < 0)
		rev *= -1;
	if (mag <= rev)
		return (1);
	else
		return (0);
}

int	get_magnitude(t_stack *stk, t_stack **stks)
{
	if (stks[B])
		return (stk->abs_pos - stk->init_pos);
	else
		return (stk->abs_pos - stk->init_pos);
}

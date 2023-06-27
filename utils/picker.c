/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:42:10 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:42:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_picker	*init_picker(t_stack *stk, int abs_pos)
{
	t_picker	*pck;

	if (stk != NULL && abs_pos > 0)
	{
		pck = (t_picker *)malloc(sizeof(t_picker));
		pck->size = stk->size;
		pck->abs_pos = abs_pos;
		while (stk->abs_pos != abs_pos)
			stk = stk->next;
		pck->cur_pos = stk->cur_pos;
		if (pck->cur_pos <= pck->size / 2 + 1)
			pck->dir = TOP;
		else
			pck->dir = BOT;
		pck->steps = get_steps(pck->cur_pos, pck->size);
	}
	else
		pck = NULL;
	return (pck);
}

// Apply a shared move order if it is possible, according with its direction.
static void	shared_move(t_picker **pck, t_stack **stk)
{
	if (pck[A] && pck[B] && pck[A]->steps > 0 && pck[B]->steps > 0)
	{
		pck[A]->steps--;
		pck[B]->steps--;
		if (pck[A]->dir == TOP)
			rr(stk);
		else if (pck[A]->dir == BOT)
			rrr(stk);
	}
}

// Apply a move order according to its direction.
static void	move(t_picker **pck, t_stack **stk, void (*r)(t_stack **),
				void (*rr)(t_stack **))
{
	if (*pck)
	{
		(*pck)->steps--;
		if ((*pck)->dir == TOP)
			r(stk);
		else if ((*pck)->dir == BOT)
			rr(stk);
	}
}

// Verify if a shorcut is available, then remap the paths.
static void	check_shortcut(t_picker **sa, t_picker **sb)
{
	int	shia;
	int	shib;

	shia = get_shortcut(&*sa, &*sb);
	shib = get_shortcut(&*sb, &*sa);
	if ((shia != 0 && shib == 0)
		|| (shia != 0 && shia <= shib))
	{
		if ((shia - (*sb)->steps) <= (*sa)->steps)
		{
			(*sa)->steps = shia;
			(*sa)->dir = (*sb)->dir;
		}
	}
	else if ((shia == 0 && shib != 0)
		|| (shib != 0 && shib < shia))
	{
		if ((shib - (*sa)->steps) <= (*sb)->steps)
		{
			(*sb)->steps = shib;
			(*sb)->dir = (*sa)->dir;
		}
	}
}

/* 
Pick the selected absolute position for each respective stack and move it 
to its top attempting to perform the least amount of moves.
*/
void	picker(t_stack **stk, int val_a, int val_b)
{
	t_picker	*pck[2];

	pck[A] = init_picker(stk[A], val_a);
	pck[B] = init_picker(stk[B], val_b);
	if (stk[A] && stk[B] && pck[A] && pck[B] && pck[A]->dir != pck[B]->dir)
		check_shortcut(&pck[A], &pck[B]);
	while ((pck[A] && pck[A]->steps > 0) || (pck[B] && pck[B]->steps > 0))
	{
		if (stk[A] && stk[B] && pck[A] && pck[B] && pck[A]->steps > 0
			&& pck[B]->steps > 0 && pck[A]->dir == pck[B]->dir)
		{
			shared_move(pck, stk);
			continue ;
		}
		if (stk[A] && pck[A] && pck[A]->steps > 0)
		{
			move(&pck[A], stk, ra, rra);
		}
		if (stk[B] && pck[B] && pck[B]->steps > 0)
			move(&pck[B], stk, rb, rrb);
	}
	update_cur_position(stk);
	free(pck[A]);
	free(pck[B]);
}

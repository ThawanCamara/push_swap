/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:27:29 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/15 10:27:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*build_stack(t_stack *stk, char **input)
{
	int		i;

	i = 0;
	while (input[i])
		i++;
	while (i > 0)
	{
		stk = push(stk, ft_atoi(input[i - 1]));
		i--;
	}
	return (stk);
}

t_stack	*push(t_stack *stk, int value)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (newnode == NULL)
		return (NULL);
	if (stk != NULL)
	{
		newnode->size = stk->size + 1;
		newnode->next = stk;
		stk->prev = newnode;
		newnode->tail = stk->tail;
		stk->tail = NULL;
	}
	else
	{
		newnode->size = 1;
		newnode->tail = newnode;
		newnode->next = NULL;
	}
	newnode->prev = NULL;
	newnode->value = value;
	return (newnode);
}

t_stack	*pop(t_stack *stk)
{
	t_stack	*tmp;

	tmp = stk;
	if (stk == NULL || tmp->next == NULL)
	{
		free(tmp);
		return (NULL);
	}
	stk = stk->next;
	stk->prev = NULL;
	stk->tail = tmp->tail;
	stk->size = tmp->size - 1;
	free(tmp);
	return (stk);
}

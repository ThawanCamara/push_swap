/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:55:20 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 14:55:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "colortag.h"

int	main(int argc, char *argv[])
{
	char	**input;

	input_validchars(argc, argv);
	input = input_parse(argc, argv);
	check_doubles(input);
	push_swap(input);
	input_clear(input);
	return (0);
}

static void	print_abs_list(t_stack *stk, char *name)
{
	t_stack	*tmp;
	int		size;

	tmp = stk;
	if (stk == NULL)
		size = 0;
	else
		size = tmp->size;
	ft_printf("%s%s[%d]: %s[ %s", B_PINK, name, size, RESET, GOLD);
	if (stk != NULL)
	{
		while (tmp)
		{
			ft_printf("%d(%d) %s", tmp->value, tmp->abs_pos, RESET);
			tmp = tmp->next;
		}
	}
	else
		ft_printf(" %s", RESET);
	ft_printf("%s]\n", RESET);
}

static void	print_all(t_stack **stk)
{
	print_abs_list(stk[A], "A");
	print_abs_list(stk[B], "B");
}

void	push_swap(char **input)
{
	t_stack	*stk[2];

	stk[A] = NULL;
	stk[B] = NULL;
	stk[A] = build_stack(stk[A], input);
	set_abs_position(&stk[A]);
	set_init_position(stk);
	update_cur_position(stk);
	if (!order_check(stk[A]) && stk[B] == NULL)
		three_sort(stk);
	picker(stk, 1, 0);
	if (DEBUG == 1)
	{
		print_all(stk);
		if (order_check(stk[A]) && stk[B] == NULL)
			ft_printf("%sThe list is ordered%s\n", B_GREEN, RESET);
	}
	destroy_stack(stk);
}

void	three_sort(t_stack **stk)
{
	int	prob;
	int	*cheapest;

	while (stk[A]->size > 3)
		pb(stk);
	prob = get_closest_prob(stk);
	picker(stk, prob, get_greater(stk[B]));
	swapper(stk);
	if (!stk[B])
		picker(stk, get_lesser(stk[A]), 0);
	while (stk[B])
	{
		cheapest = get_cheapest(stk);
		picker(stk, cheapest[A], cheapest[B]);
		pa(stk);
		free(cheapest);
	}
}

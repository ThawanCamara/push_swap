/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validchars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:19:30 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 18:20:43 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' ')
			return (FALSE);
		if (str[i] == '-'
			&& (ft_isdigit(str[i - 1]) || !ft_isdigit(str[i + 1])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	check_array(char **arr)
{
	int	i;

	i = 1;
	while (arr[i])
	{
		if (!check_string(arr[i++]))
			return (FALSE);
	}
	return (TRUE);
}

void	input_validchars(int argc, char *argv[])
{
	if (argc < 2)
		exit (0);
	else if (argc == 2)
	{
		if (!check_string(argv[1]))
			ft_throw_error_simple(4);
	}
	else
		if (!check_array(argv))
			ft_throw_error_simple(3);
}

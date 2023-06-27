/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:17:36 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 18:19:54 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**input_parse(int argc, char *argv[])
{
	char	**ret;
	int		i;

	i = 0;
	if (argc == 2)
		ret = ft_split(argv[1], ' ');
	else
	{
		ret = (char **)malloc(sizeof(char *) * ((argc - 1) + 1));
		if (!ret)
			return (NULL);
		while (i < argc - 1)
		{
			ret[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		ret[i] = NULL;
	}
	return (ret);
}

static void	check_out_of_bounds(long int num, char **input)
{
	if (num > (long)2147483647
		|| num < (long)-2147483648)
	{
		input_clear(input);
		ft_throw_error_simple(1);
	}
}

static long int	get_charsum(char *str, char **input)
{
	long int	sum;
	long int	mult;
	size_t		len;

	sum = 0;
	mult = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
		mult = -1;
	else
		mult = 1;
	while (len && ft_isdigit(str[len - 1]))
	{
		sum += mult * ((str[len - 1]) - 48);
		check_out_of_bounds(sum, input);
		mult *= 10;
		len--;
	}
	mult /= mult;
	return (sum * mult);
}

int	check_doubles(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (input[i])
	{
		get_charsum(input[i], input);
		while (input[j])
		{
			if (get_charsum(input[i], input) == get_charsum(input[j], input))
			{
				input_clear(input);
				ft_throw_error_simple(2);
			}		
			j++;
		}	
		i++;
		j = i + 1;
	}
	return (0);
}

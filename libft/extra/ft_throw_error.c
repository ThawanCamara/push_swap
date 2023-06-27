/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_throw_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:34:42 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 18:18:01 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_throw_error(char *msg, int error_code)
{
	ft_putendl_fd("Error", 2);
	ft_putnbr_fd(error_code, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\n", 2);
	ft_putendl_fd(msg, 2);
	exit(error_code);
}

void	ft_throw_error_simple(int error_code)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("\n", 2);
	exit(error_code);
}

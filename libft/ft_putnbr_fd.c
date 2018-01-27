/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 20:40:45 by nsehnoun          #+#    #+#             */
/*   Updated: 2017/05/01 15:28:13 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int n_2;

	if (n < 0)
	{
		n_2 = -n;
		ft_putchar_fd('-', fd);
	}
	else
		n_2 = n;
	if (n_2 >= 10)
	{
		ft_putnbr_fd((n_2 / 10), fd);
		ft_putnbr_fd((n_2 % 10), fd);
	}
	else
		ft_putchar_fd((48 + n_2), fd);
}

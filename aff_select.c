/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:13:31 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/28 22:51:05 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		fslct_putchar(int c)
{
	ft_putchar_fd(c, 2);
	return (0);
}

void	print_selected(char *str, int job, int cases)
{
	if (cases == 1)
	{
		tputs(tgetstr("mr", NULL), ft_strlen(str), fslct_putchar);
		ft_putstr_fd(str, 2);
		(job == 0 ? ft_putchar_fd(' ', 2) : job);
		tputs(tgetstr("me", NULL), ft_strlen(str), fslct_putchar);
	}
	if (cases == 2)
	{
		tputs(tgetstr("us", NULL), ft_strlen(str) - 1, fslct_putchar);
		ft_putstr_fd(str, 2);
		ft_putchar_fd(' ', 2);
		tputs(tgetstr("ue", NULL), ft_strlen(str) - 1, fslct_putchar);
	}
	if (cases == 3)
	{
		tputs(tgetstr("mr", NULL), ft_strlen(str), fslct_putchar);
		tputs(tgetstr("us", NULL), ft_strlen(str), fslct_putchar);
		ft_putstr_fd(str, 2);
		ft_putchar_fd(' ', 2);
		tputs(tgetstr("ue", NULL), ft_strlen(str), fslct_putchar);
		tputs(tgetstr("me", NULL), ft_strlen(str), fslct_putchar);
	}
}

void	print_exit(int err_type)
{
	if (err_type == 0)
		ft_putendl_fd("\nCould not access terminal types.", 2);
	if (err_type == 1)
		ft_putendl_fd("\nCould'nt access terminal attrs. Term type known.", 2);
	if (err_type == 2)
		ft_putendl_fd("\nCould not set terminal attrs. Access is granted.", 2);
	if (err_type == 3)
		ft_putendl_fd("\nCouldn't restore old term attrs.", 2);
	if (err_type == 4)
		ft_putendl_fd("\nProcess terminated.", 2);
	if (err_type == 5)
		ft_putendl_fd("\nCould not allocate memory.", 2);
	exit(1);
}

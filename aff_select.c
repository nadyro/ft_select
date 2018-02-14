/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_select.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:13:31 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/12 18:40:55 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		fslct_putchar(int c)
{
	ft_putchar_fd(c, 2);
	return (0);
}

void	print_selected(int task, int cases, t_list **l)
{
	if ((*l)->underlined == 1)
		tputs(tgetstr("us", NULL), 1, fslct_putchar);
	if (cases == 1 && task == 3)
	{
		tputs(tgetstr("mr", NULL), 1, fslct_putchar);
		(*l)->underlined = 0;
		ft_putstr_fd((*l)->content, 2);
		tputs(tgetstr("me", NULL), 1, fslct_putchar);
	}
	if (cases == 2 && task == 2)
	{
		tputs(tgetstr("us", NULL), 1, fslct_putchar);
		ft_putstr_fd((*l)->content, 2);
		tputs(tgetstr("ue", NULL), 1, fslct_putchar);
	}
	if (cases == 3 && task == 1)
	{
		tputs(tgetstr("mr", NULL), 1, fslct_putchar);
		tputs(tgetstr("us", NULL), 1, fslct_putchar);
		ft_putstr_fd((*l)->content, 2);
		tputs(tgetstr("ue", NULL), 1, fslct_putchar);
		tputs(tgetstr("me", NULL), 1, fslct_putchar);
	}
	if ((*l)->underlined == 1)
		tputs(tgetstr("ue", NULL), 1, fslct_putchar);
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

void	control_selected(int s, t_list **l)
{
	if ((*l) != NULL)
	{
		if (s == 1 && (*l)->selected == 1 && (*l)->deleted == 0)
		{
			(*l)->selected = 0;
			ft_putstr_fd((*l)->content, 2);
			if ((*l)->next)
				(*l)->next->underlined = 1;
		}
		else if (s == 1 && (*l)->deleted == 0)
		{
			tputs(tgetstr("mr", NULL), 1, fslct_putchar);
			(*l)->selected = 1;
			ft_putstr_fd((*l)->content, 2);
			if ((*l)->next)
				(*l)->next->underlined = 1;
			tputs(tgetstr("me", NULL), 1, fslct_putchar);
		}
		else if ((*l)->selected == 1 && (*l)->deleted == 0)
			print_selected(1, 3, l);
		else if (s == 0 && (*l)->deleted == 0)
			print_selected(2, 2, l);
	}
}

void	control_others(t_list **l)
{
	if ((*l)->selected == 1 && (*l)->deleted == 0)
		print_selected(3, 1, l);
	else if ((*l)->underlined == 1)
	{
		print_selected(2, 2, l);
		(*l)->underlined = 0;
	}
	else if ((*l)->deleted == 0)
		ft_putstr_fd((*l)->content, 2);
}

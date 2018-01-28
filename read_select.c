/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:49:57 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/28 22:53:26 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	get_list(t_list **lst)
{
	while ((*lst))
	{
		if ((*lst)->next != NULL)
		{
			ft_putstr_fd((*lst)->content, 1);
			ft_putchar_fd(' ', 1);
		}
		else
			ft_putstr_fd((*lst)->content, 1);
		(*lst) = (*lst)->next;
	}
}

void	puts_fd(char *str, int end, int index, t_list *l)
{
	t_list	*lst;
	int		active;

	lst = l;
	active = 0;
	while (lst)
	{
		if (lst->selected == index)
		{
			active = 1;
			lst = lst->next;
			break ;
		}
		lst = lst->next;
	}
	if (active == 1)
		print_selected(str, end, 1);
	else
	{
		ft_putstr_fd(str, 2);
		if (end == 0)
			ft_putchar_fd(' ', 2);
	}
}

void	put_text(char *str, t_list *lst, int index)
{
	t_list	*l;
	int		active;

	active = 0;
	l = lst;
	while (l)
	{
		if (l->selected == index)
		{
			active = 1;
			l = l->next;
			break ;
		}
		l = l->next;
	}
	if (active == 1)
		print_selected(str, 0, 3);
	else
		print_selected(str, 0, 2);
}

void	args_cursor(char **argv)
{
	int		j;
	char	*inst;
	t_list	*largs;

	largs = NULL;
	j = 2;
	if (argv[1])
	{
		put_text(argv[1], largs, 1);
		while (argv[j])
		{
			ft_putstr_fd(argv[j++], 2);
			ft_putchar_fd(' ', 2);
		}
		inst = tgetstr("cm", NULL);
		tputs(tgoto(inst, 0, 0), 1, fslct_putchar);
	}
}

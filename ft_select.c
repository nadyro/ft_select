/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:33:09 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/13 16:18:22 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		list_length(t_list *lst)
{
	int		i;
	t_list	*l;

	l = lst;
	i = 0;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

void	print_args(t_list *l)
{
	t_list			*lst;
	struct s_inf	*infos;

	lst = l;
	infos = manage_display_on_winch(l);
	if (infos->tmp < infos->len_args)
		exit_to_origin(getenv("TERM"), 1, infos);
	while (lst)
	{
		infos = adapt_display_on_winch(infos, lst->content);
		if (lst->previous == NULL)
		{
			tputs(tgetstr("us", NULL), 1, fslct_putchar);
			ft_putstr_fd(lst->content, 2);
			tputs(tgetstr("ue", NULL), 1, fslct_putchar);
		}
		else
			ft_putstr_fd(lst->content, 2);
		print_to_adjust(infos, lst->content);
		lst = lst->next;
	}
	free(infos);
}

void	is_to_del(int d, t_list **l, int *pos)
{
	if (d == 1)
	{
		if ((*l)->next != NULL)
			manage_deletion(l);
		else
			del_last(l, pos);
	}
}

void	ft_select(void)
{
	int					n;
	int					l;
	int					pos;
	char				key[4];

	l = 0;
	pos = 0;
	while (1)
	{
		manage_signals();
		manage_winch(&pos);
		if ((n = read(0, key, 3)) != -1)
		{
			key[n] = '\0';
			if (key[0] == 27)
				key_assist(key, &l, &pos);
			if (key[0] == 27 && !key[1])
				exit_to_origin(getenv("TERM"), 0, NULL);
			selection_assist(key, &l, &pos);
			if (exit_or_delete(key, &pos) < 3)
				break ;
		}
	}
	tputs(tgetstr("te", NULL), 1, fslct_putchar);
	tputs(tgetstr("ve", NULL), 1, fslct_putchar);
}

void	print_final_selection(void)
{
	t_list	*first;
	t_list	*lst;
	t_list	*list;

	lst = NULL;
	first = first_singleton(NULL);
	while (first)
	{
		if (first->selected)
			copy_into_list(&lst, first->content);
		first = first->next;
	}
	list = lst;
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		if (list->next != NULL)
			ft_putchar_fd(' ', 1);
		list = list->next;
	}
}

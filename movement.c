/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:13:23 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/14 23:45:37 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_to_origin(char *term, int err, struct s_inf *infos)
{
	tputs(tgetstr("ve", NULL), 1, fslct_putchar);
	tputs(tgetstr("te", NULL), 1, fslct_putchar);
	getentry_term(term, 1);
	if (err == 1)
		ft_putendl_fd("La fenêtre est trop petite !", 2);
	free(infos);
	exit(0);
}

void	move_out(t_list **lst, int *pos, int s, int d)
{
	t_list			*l;
	int				i;
	struct s_inf	*infos;

	i = 0;
	l = (*lst);
	infos = manage_display_on_winch(*lst);
	while (l)
	{
		infos = adapt_display_on_winch(infos, l->content);
		if (i++ == *pos)
		{
			is_to_del(d, &l, pos);
			control_selected(s, &l);
		}
		else
			control_others(&l);
		if (l != NULL)
			print_to_adjust(infos, l->content);
		if (l != NULL)
			l = l->next;
		else
			exit_to_origin(getenv("TERM"), 0, infos);
	}
	free(infos);
}

void	key_assist(char *key, int *l, int *pos)
{
	int		sub_pos;
	t_list	*first;

	sub_pos = *pos;
	first = first_singleton(NULL);
	if (key[1] == 91)
	{
		if (key[2] == 68)
		{
			*l = list_length(first);
			*pos = --sub_pos;
			(*pos < 0 ? *pos = *l - 1 : *pos);
			tputs(tgetstr("cl", NULL), 1, fslct_putchar);
			move_out(&first, pos, 0, 0);
		}
		if (key[2] == 67)
		{
			*l = list_length(first);
			*pos = ++sub_pos;
			(*pos >= *l ? *pos = 0 : *pos);
			tputs(tgetstr("cl", NULL), 1, fslct_putchar);
			move_out(&first, pos, 0, 0);
		}
	}
}

void	selection_assist(char *key, int *l, int *pos)
{
	int		sub_pos;
	t_list	*first;

	first = first_singleton(NULL);
	sub_pos = *pos;
	if (key[0] == 32)
	{
		*l = list_length(first);
		if (*pos >= *l)
			*pos = 0;
		tputs(tgetstr("cl", NULL), 1, fslct_putchar);
		move_out(&first, pos, 1, 0);
		*pos = ++sub_pos;
	}
	if (*pos >= *l)
	{
		*pos = 0;
		tputs(tgetstr("cl", NULL), 1, fslct_putchar);
		move_out(&first, pos, 0, 0);
	}
}

int		exit_or_delete(char *key, int *pos)
{
	t_list	*first;

	first = first_singleton(NULL);
	if (key && key[0] == 10)
		return (1);
	if (key && (key[0] == 8 || key[0] == 127))
	{
		tputs(tgetstr("cl", NULL), 0, fslct_putchar);
		move_out(&first, pos, 0, 1);
		if (first == NULL)
			return (0);
	}
	else if (!key && pos == 0)
		exit_to_origin(getenv("TERM"), 0, NULL);
	return (3);
}

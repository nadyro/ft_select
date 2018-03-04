/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:29:28 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/15 07:47:03 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct s_inf	*init_struct(void)
{
	struct winsize	w;
	struct s_inf	*infos;

	if (!(infos = (struct s_inf*)malloc(sizeof(struct s_inf))))
		return (NULL);
	ioctl(2, TIOCGWINSZ, &w);
	infos->rows = w.ws_row;
	infos->cols = w.ws_col;
	return (infos);
}

void			manage_winch(int *pos)
{
	t_list				*first;

	if (g_p == 1)
	{
		tputs(tgoto(tgetstr("cl", NULL), 0, 0), 1, fslct_putchar);
		first = first_singleton(NULL);
		move_out(&first, pos, 0, 0);
		g_p = 0;
	}
}

struct s_inf	*manage_display_on_winch(t_list *l)
{
	struct s_inf	*infos;
	t_list			*lst;

	infos = init_struct();
	lst = l;
	infos->len_args = 0;
	infos->tmp_rows = 0;
	infos->tmp = (infos->cols * infos->rows);
	infos->max_len = 0;
	while (lst)
	{
		if (infos->max_len < ft_strlen(lst->content))
			infos->max_len = ft_strlen(lst->content);
		infos->len_args += (ft_strlen(lst->content) + 7);
		infos->tmp_lenargs += (ft_strlen(lst->content) + 7);
		if (infos->tmp_lenargs >= infos->cols)
		{
			infos->tmp_lenargs = 0;
			infos->tmp_rows++;
		}
		lst = lst->next;
	}
	lst = l;
	infos->tmp_rows += 7;
	return (infos);
}

struct s_inf	*adapt_display_on_winch(struct s_inf *infos, char *s)
{
	int		nb_space_len;

	nb_space_len = infos->max_len - ft_strlen(s);
	infos->len_args += ft_strlen(s);
	infos->len_args += (nb_space_len + 7);
	if (infos->len_args + (ft_strlen(s) + nb_space_len + 7) >= infos->cols)
	{
		ft_putchar_fd('\n', 2);
		infos->len_args = 0;
	}
	return (infos);
}

void			print_to_adjust(struct s_inf *infos, char *s)
{
	int				nb_space_len;
	int				x;

	x = 0;
	nb_space_len = infos->max_len - ft_strlen(s);
	while (x < (nb_space_len + 7))
	{
		ft_putchar_fd(' ', 2);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:33:18 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/28 23:20:17 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	char	key[4];
	int		j;
	int		y;
	int		n;
	t_list	*lst;
	t_list	*l_args;

	(void)argc;
	getentry_term(getenv("TERM"), 0);
	j = 1;
	y = 1;
	args_cursor(argv);
	n = 0;
	tputs(tgetstr("vi", NULL), 1, fslct_putchar);
	lst = NULL;
	l_args = NULL;
	while (1)
	{
		if ((n = read(0, key, 3)) != -1)
		{
			key[n] = '\0';
			tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, fslct_putchar);
			if (key[0] == 27)
			{
				if (key[1] == 91)
				{
					if (key[2] == 68)
						move_up(argv, &j, &y, l_args);
					if (key[2] == 67)
						move_down(argv, &j, &y, l_args);
				}
			}
			if (key[0] == 27 && !key[1])
			{
				tputs(tgetstr("cl", NULL), 1, fslct_putchar);
				ft_lstdel(&lst, ft_bzero);
				tputs(tgetstr("ve", NULL), 1, fslct_putchar);
				getentry_term(getenv("TERM"), 1);
			}
			if (key[0] == 32)
			{
				list_args(&l_args, y);
				manage_selected_items(&lst, &y, argv, l_args);
			}
			if (key[0] == 111)
				break;
			if (key[0] == 13)
				break;
			if (key[0] == 8 || key[0] == 127)
			{
				break;
			}
		}
	}
	tputs(tgetstr("cl", NULL), 1, fslct_putchar);
	if (lst)
	{
		get_list(&lst);
		ft_lstdel(&lst, ft_bzero);
	}
	tputs(tgetstr("ve", NULL), 1, fslct_putchar);
	getentry_term(getenv("TERM"), 1);
	return (0);
}

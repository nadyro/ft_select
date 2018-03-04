/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:33:18 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/15 07:47:19 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	int				i;
	t_list			*lst;
	t_list			*first;

	i = 1;
	lst = NULL;
	first = NULL;
	if (argc == 1)
		print_exit(6);
	while (i < argc)
		copy_into_list(&first, argv[i++]);
	getentry_term(getenv("TERM"), 0);
	first_singleton(first);
	lst = first;
	print_args(lst);
	ft_select();
	if (g_p != 2)
	{
		getentry_term(getenv("TERM"), 1);
		print_final_selection();
		first = first_singleton(NULL);
		ft_lstdel(&first, ft_bzero);
	}
	return (0);
}

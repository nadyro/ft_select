/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:14:34 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/13 04:54:08 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios term;

void	configure_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

void	getentry_term(char *terminal, int is_end)
{
	struct termios t;

	if ((tgetent(NULL, terminal)) == -1)
		print_exit(0);
	if (tcgetattr(0, &term) == -1)
		print_exit(1);
	t = term;
	if (is_end == 0)
	{
		configure_term(&t);
		tputs(tgetstr("ti", NULL), 1, fslct_putchar);
		tputs(tgetstr("vi", NULL), 1, fslct_putchar);
		if (tcsetattr(0, TCSADRAIN, &t) == -1)
		{
			tputs(tgetstr("te", NULL), 1, fslct_putchar);
			tputs(tgetstr("ve", NULL), 1, fslct_putchar);
			print_exit(2);
		}
	}
	else if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		tputs(tgetstr("te", NULL), 1, fslct_putchar);
		tputs(tgetstr("ve", NULL), 1, fslct_putchar);
		print_exit(2);
	}
}

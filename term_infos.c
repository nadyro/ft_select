/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:14:34 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/28 23:20:41 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	configure_term(struct termios *term, int is_end)
{
	if (is_end == 1)
	{
		term->c_lflag = ICANON;
		term->c_lflag = ECHO;
		if (tcsetattr(0, 0, term) == -1)
			print_exit(3);
		print_exit(4);
	}
	else
	{
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
	}
}

void	getentry_term(char *terminal, int is_end)
{
	struct termios	term;

	if ((tgetent(NULL, terminal)) == -1)
		print_exit(0);
	if (tcgetattr(0, &term) == -1)
		print_exit(1);
	if (is_end == 1)
		configure_term(&term, 1);
	configure_term(&term, 0);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		print_exit(2);
}

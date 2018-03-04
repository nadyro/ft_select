/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:52:58 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/15 07:40:15 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		g_p;
int		*g_sig_pos;

void	manage_signals(void)
{
	struct sigaction	sa;
	int					i;

	i = 1;
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = signal_handling;
	sa.sa_flags = SA_SIGINFO;
	while (i < 32)
	{
		sigaction(i, &sa, NULL);
		i++;
	}
}

void	is_tstp(int i, char *str)
{
	if (i == SIGTSTP)
	{
		tputs(tgetstr("te", NULL), 1, fslct_putchar);
		tputs(tgetstr("ve", NULL), 1, fslct_putchar);
		signal(SIGTSTP, SIG_DFL);
		ioctl(2, TIOCSTI, str);
	}
}

void	is_cont(int i)
{
	if (i == SIGCONT)
	{
		g_p = 1;
		getentry_term(getenv("TERM"), 0);
		manage_winch(g_sig_pos);
	}
}

void	signal_handling(int signum)
{
	int		i;
	char	str[2];

	i = 1;
	str[0] = 26;
	str[1] = '\0';
	while (i < 32)
	{
		if (i == signum)
		{
			if (i == SIGWINCH)
			{
				g_p = 1;
				break ;
			}
			is_tstp(i, str);
			is_cont(i);
			if (signum != SIGCONT && i != SIGTSTP)
				exit_or_delete(NULL, 0);
		}
		i++;
	}
}

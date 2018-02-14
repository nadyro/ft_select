/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:52:58 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/14 23:07:45 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_select.h"

int		g_p;

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

void	signal_handling(int signum)
{
	int		i;

	i = 1;
	g_p = 0;
	while (i < 32)
	{
		if (i == SIGWINCH && signum == i)
			g_p = 1;
		else if (signum == i)
			exit_or_delete(NULL, 0);
		i++;
	}
}

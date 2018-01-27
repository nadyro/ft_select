/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:53:26 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/24 15:55:58 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_type(int signo)
{
	if (signo == SIGUSR1)
		ft_putendl("Caught SIGUSR1");
	if (signo == SIGKILL)
		ft_putendl("Caught SIGKILL");
	if (signo == SIGSTOP)
		ft_putendl("Caught SIGSTOP");
}

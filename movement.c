/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:37:55 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/28 20:12:52 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		count_args(char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	move_up(char **a, int *j, int *y, t_list *l)
{
	int		i;
	int		x;
	int		z;

	i = count_args(a);
	x = *j;
	z = *y;
	x = 1;
	z--;
	if (z == 0)
		z = i - 1;
	tputs(tgetstr("cl", NULL), 1, fslct_putchar);
	while (a[x])
	{
		if (x == z)
			put_text(a[z], l, z);
		if (z != x)
			(x + 1 == i ? puts_fd(a[x], 1, x, l) : puts_fd(a[x], 0, x, l));
		x++;
	}
	*j = x;
	*y = z;
}

void	move_down(char **a, int *j, int *y, t_list *l)
{
	int		i;
	int		x;
	int		z;

	i = count_args(a);
	x = *j;
	z = *y;
	x = 0;
	z++;
	(z >= i ? z = 1 : z);
	tputs(tgetstr("cl", NULL), 1, fslct_putchar);
	while (a[++x])
	{
		if (x == z)
		{
			put_text(a[x], l, x);
			if (x + 1 != i)
				x++;
		}
		if (z != x)
			(x + 1 == i ? puts_fd(a[x], 1, x, l) : puts_fd(a[x], 0, x, l));
	}
	*j = x;
	*y = z;
}

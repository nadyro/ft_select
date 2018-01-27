/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 23:31:28 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/27 23:00:01 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list	*list_args(t_list **lst, int y)
{
	t_list	*head;
	t_list	*node;

	head = (*lst);
	node = NULL;
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	node->selected = y;
	node->next = NULL;
	if ((*lst) == NULL)
	{
		(*lst) = node;
		return ((*lst));
	}
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	return ((*lst));
}

int		print_return_ptr(int ix, int y, char **argv, t_list *l)
{
	int		i;

	i = count_args(argv);
	if (ix == y)
	{
		put_text(argv[ix], l, ix);
		if (ix + 1 != i)
			ix++;
	}
	return (ix);
}

void	print_afterselect(char **a, int *y, t_list *l)
{
	int		sub_y;
	int		x;
	int		j;

	sub_y = *y;
	j = count_args(a);
	x = 0;
	(x >= j ? x = 1 : x);
	while (a[++x])
	{
		x = print_return_ptr(x, sub_y, a, l);
		if (sub_y != x && x != j)
		{
			if (x - 1 == sub_y)
			{
				put_text(a[x], l, x);
				x++;
			}
			if (x != j)
				(x + 1 == j ? puts_fd(a[x], 1, x, l) : puts_fd(a[x], 0, x, l));
		}
		(x == j ? x-- : x);
	}
	sub_y++;
	*y = sub_y;
}

void	manage_selected_items(t_list **lst, int *y, char **argv, t_list *l)
{
	t_list	*head;
	t_list	*node;
	int		j;

	j = count_args(argv);
	head = (*lst);
	node = NULL;
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		print_exit(5);
	(*y >= j ? *y = 1 : *y);
	node->content = argv[*y];
	node->content_size = ft_strlen(argv[*y]);
	node->next = NULL;
	tputs(tgetstr("cl", NULL), 1, fslct_putchar);
	if ((*lst) == NULL)
	{
		(*lst) = node;
		print_afterselect(argv, y, l);
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	print_afterselect(argv, y, l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:58:12 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/15 06:34:28 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	copy_into_list(t_list **lst, char *argv)
{
	t_list *head;
	t_list *node;

	head = *lst;
	node = NULL;
	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return ;
	node->content = argv;
	node->content_size = ft_strlen(argv);
	node->selected = 0;
	node->deleted = 0;
	node->underlined = 0;
	node->next = NULL;
	if ((*lst) == NULL)
	{
		node->previous = NULL;
		(*lst) = node;
		return ;
	}
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	node->previous = head;
	return ;
}

void	manage_deletion(t_list **l)
{
	if ((*l)->previous == NULL)
		del_head(l);
	else
		del_center(l);
}

void	del_head(t_list **to_del)
{
	t_list	*next;

	next = (*to_del)->next;
	free(*to_del);
	(*to_del) = next;
	(*to_del)->previous = NULL;
	first_singleton((*to_del));
}

void	del_center(t_list **l)
{
	t_list	*list;
	t_list	*list1;

	list = (*l)->previous;
	list1 = (*l)->next;
	list->next = list1;
	list1->previous = list;
	free((*l));
	(*l) = list;
	(*l) = (*l)->next;
}

void	del_last(t_list **l, int *pos)
{
	t_list	*lst;
	t_list	*first;

	first = first_singleton(NULL);
	lst = NULL;
	if ((*l)->previous != NULL)
	{
		lst = (*l)->previous;
		free((*l));
		lst->next = NULL;
		*l = first;
	}
	else
	{
		free((*l));
		(*l) = NULL;
		first = NULL;
	}
	*pos = 0;
	tputs(tgetstr("cl", NULL), 1, fslct_putchar);
}

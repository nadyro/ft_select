/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:40:53 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/01/27 23:09:04 by nsehnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft/libft.h"
# include <sys/ioctl.h>
# include <termcap.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <curses.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>

void	getentry_term(char *term, int is_end);
int		fslct_putchar(int c);
void	read_select(t_list *list);
void	put_text(char *str, t_list *lst, int index);
void	move_down(char **argv, int *j, int *y, t_list *l);
void	move_up(char **argv, int *j, int *y, t_list *l);
void	args_cursor(char **argv);
void	manage_selected_items(t_list **lst, int *y, char **argv, t_list *l);
void	get_list(t_list **lst);
void	sig_type(int signo);
void	puts_fd(char *str, int end, int index, t_list *l);
void	print_exit(int err_type);
void	configure_term(struct termios *term, int is_end);
int		count_args(char **argv);
t_list	*list_args(t_list **lst, int y);
void	select_items(char **argv, t_list *largs, int *j, int *y);
void	print_selected(char *str, int job, int cases);
int		print_return_ptr(int ix, int y, char **argv, t_list *l);
void	print_afterselect(char **argv, int *y, t_list *lst);
#endif

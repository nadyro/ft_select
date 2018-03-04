/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsehnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:40:53 by nsehnoun          #+#    #+#             */
/*   Updated: 2018/02/15 05:50:50 by nsehnoun         ###   ########.fr       */
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

extern int		g_p;
extern int		*g_sig_pos;
extern struct termios	term;
struct			s_inf {

	size_t		rows;
	size_t		cols;
	size_t		len_args;
	size_t		tmp;
	size_t		tmp_rows;
	size_t		tmp_lenargs;
	size_t		max_len;
};
void			getentry_term(char *term, int is_end);
void			configure_term(struct termios *term);
void			print_exit(int err_type);
int				fslct_putchar(int c);
void			print_selected(int task, int cases, t_list **l);
void			control_selected(int s, t_list **l);
void			control_others(t_list **l);
void			copy_into_list(t_list **lst, char *argv);
void			manage_deletion(t_list **l);
void			del_head(t_list **to_del);
void			del_center(t_list **l);
void			del_last(t_list **l, int *pos);
void			move_out(t_list **lst, int *pos, int s, int d);
void			exit_to_origin(char *term, int err, struct s_inf *infos);
void			key_assist(char *key, int *l, int *pos);
void			selection_assist(char *key, int *l, int *pos);
int				exit_or_delete(char *key, int *pos);
int				list_length(t_list *lst);
void			print_args(t_list *l);
void			ft_select(void);
void			print_final_selection(void);
void			signal_handling(int signum);
struct s_inf	*init_struct(void);
t_list			*first_singleton(t_list *lst);
void			manage_signals(void);
void			manage_winch(int *pos);
struct s_inf	*manage_display_on_winch(t_list *l);
struct s_inf	*adapt_display_on_winch(struct s_inf *infos, char *s);
void			is_to_del(int d, t_list **l, int *pos);
void			print_to_adjust(struct s_inf *infos, char *s);
void			is_tstp(int i, char *str);
void			is_cont(int i);
#endif

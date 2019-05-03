/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:38:21 by conoel            #+#    #+#             */
/*   Updated: 2019/05/03 13:22:42 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "haflib.h"

struct termios	g_term_mem;
int				g_fd;

typedef struct	s_term
{
	char			*name;
	struct termios	term;
}				t_term;

typedef struct	s_infos
{
	int	original_x;
	int	original_y;
	int	*selected;
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	max_len;
	int	current_index;
	int	nb_args;
}				t_infos;

typedef struct	s_handlers
{
	int		(*test)(char *buff, t_infos *infos);
	void	(*handler)(char ***args, t_infos *infos);
}				t_handlers;

int				ft_putchar_stdout(int c);
void			end(int no);

int				init_term(t_term *term);
void 			init_infos(t_infos *infos, char **args, int mode);
int 			read_key(char **args);
void			display(char **choices, t_infos *infos);

char			**copy_tabl(size_t size, char **tabl);
int				*realloc_int_tab(size_t remove_index, int *tabl, size_t size);
char			**realloc_tabl_remove_index(char **tabl, size_t index);
int				get_longer(char **tabl);
int				tab_len(char **tabl);

void			handle_left(char ***args, t_infos *infos);
int				test_left(char *buff, t_infos *infos);
void			handle_right(char ***args, t_infos *infos);
int				test_right(char *buff, t_infos *infos);
void			handle_down(char ***args, t_infos *infos);
int				test_down(char *buff, t_infos *infos);
void			handle_up(char ***args, t_infos *infos);
int				test_up(char *buff, t_infos *infos);
void			handle_del(char ***args, t_infos *infos);
int				test_del(char *buff, t_infos *infos);
void			handle_escape(char ***args, t_infos *infos);
int				test_escape(char *buff, t_infos *infos);
int				test_space(char *buff, t_infos *infos);
void			handle_space(char ***args, t_infos *infos);
int				test_enter(char *buff, t_infos *infos);
void			handle_enter(char ***args, t_infos *infos);

#endif
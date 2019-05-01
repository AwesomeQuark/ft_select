/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:38:21 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 21:05:56 by conoel           ###   ########.fr       */
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

typedef struct	s_term
{
	char			*name;
	struct termios	term;
	int				fd;
}				t_term;

typedef struct	s_infos
{
	int	*selected;
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	nb_col;
	int	nb_lin;
	int	max_len;
}				t_infos;

int		ft_putchar(int c);
void	signal_handler(int no);

int		init_term(t_term *term);
int		read_key(char **args);

char	**copy_tabl(size_t size, char **tabl);
char	**realloc_tabl_remove_index(char **tabl, size_t index);
int		get_longer(char **tabl);
int		tab_len(char **tabl);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:38:21 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 19:22:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "haflib.h"

typedef struct	s_term
{
	char			*name;
	struct termios	term;
	struct termios	term_mem;
	int				fd;
}				t_term;

int		ft_putchar(int c);

int		init_term(t_term *term);
int		read_key(char **args);

char	**copy_tabl(size_t size, char **tabl);


#endif
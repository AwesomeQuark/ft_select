/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:35:29 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 20:55:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int no)
{
	int	fd;
	
	no = 0;
	fd = open(ttyname(0), O_RDWR);
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
	tcsetattr(fd, 0, &(g_term_mem));
	exit(1);
}

int		main(int argc, char **argv)
{
	t_term 	term;
	char **args;

	signal(SIGINT, signal_handler);
	if (!init_term(&term))
		return (0);
	args = copy_tabl(argc + 1, argv);
	args = realloc_tabl_remove_index(args, 0);
	read_key(args);
	tcsetattr(term.fd, 0, &(g_term_mem));
}
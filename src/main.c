/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:35:29 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 18:54:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_putchar_stdout(int c)
{
	write(0, &c, 1);
	return (0);
}

void					end(int no)
{
	if (no)
		tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	tcsetattr(g_fd, TCSANOW, &g_term_mem);
	close(g_fd);
	exit(1);
}

int						main(int argc, char **argv)
{
	t_term 	term;
	char **args;

	if (argc == 1)
		return (return_("Usage: ./ft_select [arg1] [arg2] [arg3] ...\n"));
	if (argc == 2)
	{
		ft_putstr_fd(argv[1], 1);
		return (1);
	}
	signal(SIGINT, end);
	if (!init_term(&term))
		return (0);
	args = copy_tabl(argc + 1, argv);
	args = realloc_tabl_remove_index(args, 0);
	read_key(args);
	end(1);
	return (0);
}
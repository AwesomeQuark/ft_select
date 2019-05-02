/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:35:29 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 13:50:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	*get_termmem(struct termios *term_mem)
{
	static struct termios *term;

	if (term_mem == NULL)
		return (term);
	else
	{
		term = term_mem;
		return (NULL);
	}
}

void					end(int no)
{
	int	fd;
	static struct termios *term_mem;
	
	no = 0;
	term_mem = get_termmem(NULL);
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
	fd = open(ttyname(0), O_RDWR);
	tcsetattr(fd, 0, term_mem);
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
}
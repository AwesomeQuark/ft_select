/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 12:35:29 by conoel            #+#    #+#             */
/*   Updated: 2019/05/22 20:12:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_putchar_stdout(int c)
{
	write(0, &c, 1);
	return (0);
}

static int	errors(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "-v") == 0))
		return (return_("Usage: ./ft_select [-v] [arg1] [arg2] [arg3] ...\n"));
	if ((argc == 2 && ft_strcmp(argv[1], "-v")))
	{
		ft_putstr_fd(argv[1], 1);
		return (0);
	}
	if (argc == 3 && ft_strcmp(argv[1], "-v") == 0)
	{
		ft_putstr_fd(argv[2], 1);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_term	term;
	int		visual;

	if (!(errors(argc, argv)))
		return (EXIT_FAILURE);
	if (!init_term(&term))
		return (return_("Your shell doesn't support Termcaps.\n"));
	visual = 0;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		visual = 1;
		g_argv = copy_tabl(argc, &argv[2]);
	}
	else
		g_argv = copy_tabl(argc + 1, &argv[1]);
	read_key(visual);
	end(1);
}

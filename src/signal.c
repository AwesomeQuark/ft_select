/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:27:18 by conoel            #+#    #+#             */
/*   Updated: 2019/05/07 14:57:13 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	stop(int no)
{
	int		i;
	char	ctrlz[2];

	i = 0;
	ctrlz[0] = 26;
	ctrlz[1] = 0;
	(void)no;
	tcsetattr(0, TCSANOW, &g_term_mem);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_stdout);
	while (i < NSIG)
	{
		if (i != SIGCONT)
			signal(i, SIG_DFL);
		i++;
	}
	ioctl(0, TIOCSTI, ctrlz);
}

void continue_(int no)
{
	t_term term;

	(void)no;
	init_term(&term);
	signal_wrapper();
}

void end(int no)
{
	if (no != 0)
//		tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	free_tab(g_argv);
	tcsetattr(0, TCSANOW, &g_term_mem);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_stdout);
	exit(1);
}

void	resize(int no)
{
	(void)no;
	display(&g_infos, 1);
}

void	signal_wrapper(void)
{
	int	i;

	i = 0;
	while (i < NSIG)
	{
		if (i == SIGTSTP)
			signal(i, stop);
		else if (i == SIGCONT)
			signal(i, continue_);
		else if (i == SIGWINCH)
			signal(i, resize);
		else if (i != SIGQUIT && i != SIGKILL)
			signal(i, end);
		i++;
	}
}

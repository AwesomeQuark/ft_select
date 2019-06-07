/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:27:18 by conoel            #+#    #+#             */
/*   Updated: 2019/05/26 12:33:44 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		stop(int no)
{
	int		i;
	char	ctrlz[2];

	i = 0;
	ctrlz[0] = 26;
	ctrlz[1] = 0;
	(void)no;
	tputs(tgetstr("te", NULL), 1, ft_putchar_stdout);
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

void		continue_(int no)
{
	t_term term;

	(void)no;
	init_term(&term);
	signal_wrapper();
	display(&g_infos);
}

void		end(int no)
{
	(void)no;
	free_tab(g_argv);
	tcsetattr(0, TCSANOW, &g_term_mem);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_stdout);
	tputs(tgetstr("te", NULL), 1, ft_putchar_stdout);
	exit(no);
}

void		resize(int no)
{
	(void)no;
	display(&g_infos);
	signal(no, resize);
}

void		signal_wrapper(void)
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
		else if (i != SIGSTOP && i != SIGKILL && i != SIGILL && i != SIGFPE
			&& i != SIGSEGV && i != SIGQUIT)
			signal(i, end);
		i++;
	}
}

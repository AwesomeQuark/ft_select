/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:33:03 by conoel            #+#    #+#             */
/*   Updated: 2019/05/05 11:12:34 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_positive(int *selected, int size)
{
	int	i;
	int	tot;

	i = 0;
	tot = 0;
	while (i < size)
	{
		if (selected[i])
			tot++;
		i++;
	}
	return (tot);
}

int		init_term(t_term *term)
{
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &g_term_mem) == -1)
		return (0);
	if (tcgetattr(0, &(term->term)) == -1)
		return (0);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &(term->term));
	tputs(tgetstr("vi", NULL), 1, ft_putchar_stdout);
	return (1);
}

void	init_infos(t_infos *infos, int mode)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	infos->max_len = get_longer(g_argv) + 2;
	infos->max_x = w.ws_col / infos->max_len;
	infos->nb_args = tab_len(g_argv);
	infos->max_y = infos->nb_args / infos->max_x;
	infos->current_index = infos->x + (infos->y * infos->max_x);
	infos->nb_selected = get_positive(infos->selected, infos->nb_args);
	if (infos->current_index >= infos->nb_args || infos->current_index < 0)
	{
		infos->x = 0;
		infos->y = 0;
		infos->current_index = 0;
	}
	if (mode)
	{
		infos->completion = NULL;
		infos->x = 0;
		infos->y = 0;
		if (!(infos->selected = malloc(sizeof(int) * tab_len(g_argv))))
			end(1);
		ft_bzero(infos->selected, sizeof(int) * tab_len(g_argv));
	}
	while (w.ws_row <= infos->max_y + 7)
		ioctl(0, TIOCGWINSZ, &w);
}

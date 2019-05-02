/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:33:03 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 11:03:58 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_term(t_term *term)
{
	if ((term->fd = open(ttyname(0), O_RDWR)) == -1)
		return (0);
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(term->fd, &(g_term_mem)) == -1)
		return (0);
	if (tcgetattr(term->fd, &(term->term)) == -1)
		return (0);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, 0, &(term->term)) == -1)
		return (return_("tcsetattr"));
	tputs(tgetstr("vi", NULL), 0, ft_putchar);
	return (1);
}

void	init_infos(t_infos *infos, char **args, int mode)
{
	struct winsize w;

	if (mode)
	{
		infos->x = 0;
		infos->y = 0;
	}
	ioctl(0, TIOCGWINSZ, &w);
	infos->max_len = get_longer(args) + 1;
	infos->max_x = w.ws_col / infos->max_len;
	infos->nb_args = tab_len(args);
	infos->max_y = infos->nb_args / infos->max_x;

}

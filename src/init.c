/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:33:03 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 17:19:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_term(t_term *term)
{
	struct	termios	*term_mem;

	if (!(term_mem = malloc(sizeof(struct termios))))
		end(0);
	if ((term->fd = open(ttyname(0), O_RDWR)) == -1)
		return (0);
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(term->fd, term_mem) == -1)
		return (0);
	get_termmem(term_mem);
	if (tcgetattr(term->fd, &(term->term)) == -1)
		return (0);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, 0, &(term->term)) == -1)
		return (return_("tcsetattr"));
	tputs(tgetstr("vi", NULL), 1, ft_putchar_stdout);
	return (1);
}

void	init_infos(t_infos *infos, char **args, int mode)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	infos->max_len = get_longer(args) + 1;
	infos->max_x = w.ws_col / infos->max_len;
	infos->nb_args = tab_len(args);
	infos->max_y = infos->nb_args / infos->max_x;
	infos->current_index = infos->x + (infos->y * infos->max_x);
	if (mode)
	{
		infos->original_x = 0;//wherex();
		infos->original_y = 0;//wherey();
		infos->x = 0;
		infos->y = 0;
		if (!(infos->selected = malloc(sizeof(int) * tab_len(args))))
			end(1);
		ft_bzero(infos->selected, sizeof(int) * tab_len(args));
	}
	while (w.ws_row <= infos->max_y)
		ioctl(0, TIOCGWINSZ, &w);
}

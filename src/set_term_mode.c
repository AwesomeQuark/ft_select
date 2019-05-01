/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:33:03 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 19:22:31 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	init_term(t_term *term)
{
	if ((term->fd = open(ttyname(0), O_RDWR)) == -1)
		return (0);
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(term->fd, &(term->term)) == -1)
		return (0);
	if (tcgetattr(term->fd, &(term->term_mem)) == -1)
		return (0);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	if (tcsetattr(term->fd, 0, &(term->term)) == -1)
		return (return_("tcsetattr"));
	return (1);
}
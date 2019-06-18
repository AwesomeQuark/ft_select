/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:46:42 by conoel            #+#    #+#             */
/*   Updated: 2019/06/07 15:20:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		put_x_space(int x)
{
	char *str;

	if (!(str = malloc(sizeof(char) * x)))
		end(0);
	ft_memset(str, ' ', x);
	write(0, str, x);
	free(str);
}

static void		beauty_print_args(t_infos *infos)
{
	int i;

	i = 0;
	while (g_argv[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			ft_dprintf(0, "%s%s<%s>%s","\033[41m", BLACK, g_argv[i], DEF);
		else if (infos->selected[i] == 1)
			ft_dprintf(0, "%s\033[44m%s%s", BLACK, g_argv[i], DEF);
		else if (i == infos->current_index)
			ft_dprintf(0, "%s<%s>%s", RED, g_argv[i], DEF);
		else
			ft_dprintf(0, "%s", g_argv[i]);
		if (i == infos->current_index)
			put_x_space(infos->max_len - (ft_strlen(g_argv[i]) + 2));
		else
			put_x_space(infos->max_len - ft_strlen(g_argv[i]));
		i++;
		if (modulo(i, infos->max_x) == 0)
			write(0, "\n", 1);
	}
}

static void		beauty(t_infos *infos)
{
	ft_putstr_fd(" FT # Tab : Enable search\n SE # Esc : Quit\n LE # Space : Add\
to selection\n CT # Enter : Validate selection\n-------\n", 0);
	beauty_print_args(infos);
	if (modulo(infos->nb_args, infos->max_x) != 0)
		write(0, "\n", 1);
	ft_dprintf(0, "\n%s%sTotal :%s %d ", BOLD, UNDERLINE, DEF, infos->nb_args);
	ft_dprintf(0, "%s%sSelected :%s %d", BOLD, UNDERLINE, DEF,
		infos->nb_selected);
	if (infos->completion)
	{
		ft_dprintf(0, "%p %p", infos->completion, infos->supposition);
		ft_dprintf(0, "\nCompletion: %s%s%s%s > %d input match [esc to quit]",
			infos->completion, SHADED, infos->supposition
			+ ft_strlen(infos->completion), DEF, infos->found);
	}
}

static void		classic(t_infos *infos)
{
	int i;

	i = 0;
	while (g_argv[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			ft_dprintf(0, "%s%s%s%s", UNDERLINE, REVERSE, g_argv[i], DEF);
		else if (infos->selected[i] == 1)
			ft_dprintf(0, "%s%s%s", REVERSE, g_argv[i], DEF);
		else if (i == infos->current_index)
			ft_dprintf(0, "%s%s%s", UNDERLINE, g_argv[i], DEF);
		else
			ft_dprintf(0, "%s", g_argv[i]);
		print_char_str(' ', infos->max_len - ft_strlen(g_argv[i]));
		i++;
		if (modulo(i, infos->max_x) == 0)
			write(0, "\n", 1);
	}
	ft_dprintf(0, "x: %d y: %d", infos->x, infos->y);
}

void			display(t_infos *infos)
{
	init_infos(infos, 0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar_stdout);
	if (infos->visual == 0)
		classic(infos);
	else
		beauty(infos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:46:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/05 18:33:26 by conoel           ###   ########.fr       */
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
			ft_putstr_fd("\033[1m\033[41m\033[30m<", 0);
		else if (infos->selected[i] == 1)
			ft_putstr_fd("\033[44m\033[30m", 0);
		else if (i == infos->current_index)
			ft_putstr_fd("\033[1m\033[31m<", 0);
		ft_putstr_fd(g_argv[i], 0);
		if (i == infos->current_index)
			write(0, ">", 1);
		ft_putstr_fd("\033[0m", 0);
		if (i == infos->current_index)
			put_x_space(infos->max_len - (ft_strlen(g_argv[i]) + 2));
		else
			put_x_space(infos->max_len - ft_strlen(g_argv[i]));
		i++;
		if (i % infos->max_x == 0)
			write(0, "\n", 1);
	}
}

static void		beauty(t_infos *infos)
{
	ft_putstr_fd(" FT # Tab : Enable search\n SE # Esc : Quit\n", 0);
	ft_putstr_fd(" LE # Space : Add to selection\n", 0);
	ft_putstr_fd(" CT # Enter : Validate selection\n-------\n", 0);
	beauty_print_args(infos);
	if (infos->nb_args % infos->max_x != 0)
		write(0, "\n", 1);
	ft_putstr_fd("\n\033[1m\033[4mTotal :\033[0m ", 0);
	ft_putnbr_fd(infos->nb_args, 0);
	ft_putstr_fd(" \033[1m\033[4mSelected :\033[0m ", 0);
	ft_putnbr_fd(infos->nb_selected, 0);
	if (infos->completion)
	{
		ft_putstr_fd("\nCompletion: ", 0);
		ft_putstr_fd(infos->completion, 0);
		ft_putstr_fd("\033[2m", 0);
		ft_putstr_fd(infos->supposition + ft_strlen(infos->completion), 0);
		ft_putstr_fd("\033[0m", 0);
		ft_putstr_fd(" > ", 0);
		ft_putnbr_fd(infos->found, 0);
		ft_putstr_fd(" input match", 0);
		ft_putstr_fd(" [escape to quit]\n", 0);
	}
}

static void		classic(t_infos *infos)
{
	int i;

	i = 0;
	while (g_argv[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			ft_putstr_fd("\033[7m\033[4m", 0);
		else if (infos->selected[i] == 1)
			ft_putstr_fd("\033[7m", 0);
		else if (i == infos->current_index)
			ft_putstr_fd("\033[4m", 0);
		ft_putstr_fd(g_argv[i], 0);
		ft_putstr_fd("\033[0m", 0);
		put_x_space(infos->max_len - ft_strlen(g_argv[i]));
		i++;
		if (i % infos->max_x == 0)
			write(0, "\n", 1);
	}
}

void			display(t_infos *infos, int visual)
{
	static int visual_s = -1;

	if (visual_s == -1)
		visual_s = visual;
	init_infos(infos, 0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, ft_putchar_stdout);
	if (visual_s == 0)
		classic(infos);
	else
		beauty(infos);
}

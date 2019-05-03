/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:46:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/03 17:59:36 by conoel           ###   ########.fr       */
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

static void		beauty(char **choices, t_infos *infos)
{
	int i;

	i = 0;
	while (choices[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			ft_putstr_fd("\033[41m\033[30m<", 0);
		else if (infos->selected[i] == 1)
			ft_putstr_fd("\033[44m\033[30m", 0);
		else if (i == infos->current_index)
			ft_putstr_fd("\033[31m<", 0);
		ft_putstr_fd(choices[i], 0);
		if (i == infos->current_index)
			write(0, ">", 1);
		ft_putstr_fd("\033[0m", 0);
		if (i == infos->current_index)
			put_x_space(infos->max_len - (ft_strlen(choices[i]) + 2));
		else
			put_x_space(infos->max_len - ft_strlen(choices[i]));
		if (i++ % infos->max_x == 0)
			write(0, "\n", 1);
	}
}

static void		classic(char **choices, t_infos *infos)
{
	int i;

	i = 0;
	while (choices[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			ft_putstr_fd("\033[7m\033[4m", 0);
		else if (infos->selected[i] == 1)
			ft_putstr_fd("\033[7m", 0);
		else if (i == infos->current_index)
			ft_putstr_fd("\033[4m", 0);
		ft_putstr_fd(choices[i], 0);
		ft_putstr_fd("\033[0m", 0);
		put_x_space(infos->max_len - ft_strlen(choices[i]));
		i++;
		if (i % infos->max_x == 0)
			write(0, "\n", 1);
	}
}

void			display(char **choices, t_infos *infos, int visual)
{
	init_infos(infos, choices, 0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	tputs(tgoto(tgetstr("cm", NULL), infos->original_x, infos->original_y),
		1, ft_putchar_stdout);
	if (visual == 0)
		classic(choices, infos);
	else
		beauty(choices, infos);
}

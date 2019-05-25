/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/25 19:35:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_left(t_infos *infos)
{
	if (infos->x != 0)
		infos->x--;
	else if (infos->current_index > 0)
	{
		infos->y--;
		infos->x = infos->max_x - 1;
	}
	else
	{
		infos->x = infos->nb_args % infos->max_x - 1;
		infos->y = infos->max_y;
	}
}

void	handle_right(t_infos *infos)
{
	if (infos->x != infos->max_x && infos->current_index != infos->nb_args - 1)
		infos->x++;
	else if (infos->current_index != infos->nb_args - 1)
	{
		infos->y++;
		infos->x = 0;
	}
	else
	{
		infos->x = 0;
		infos->y = 0;
	}
}

void	handle_up(t_infos *infos)
{
	if (infos->y != 0)
		infos->y--;
	else if (infos->x != 0)
	{
		if (infos->nb_args % infos->max_x < infos->x)
			infos->y = infos->max_y - 1;
		else
			infos->y = infos->max_y;
		infos->x--;
	}
	else
	{
		infos->x = infos->nb_args % infos->max_x - 1;
		infos->y = infos->max_y;
	}
}

void	handle_down(t_infos *infos)
{
	if (infos->y != infos->max_y && !(infos->y == infos->max_y - 1
		&& infos->x >= infos->nb_args % infos->max_x))
		infos->y++;
	else if (infos->x * infos->max_y != infos->nb_args)
	{
		infos->y = 0;
		infos->x++;
	}
	else
	{
		infos->x = 0;
		infos->y = infos->max_y;
	}
}

void	handle_del(t_infos *infos)
{
	if (tab_len(g_argv) == 1)
		end(1);
	if (infos->current_index == infos->nb_args - 1)
	{
		infos->y = infos->max_y;
		infos->x = (infos->nb_args - 1) % infos->max_x;
	}
	infos->selected = realloc_int_tab(infos->current_index, infos->selected,
		infos->nb_args);
	g_argv = realloc_tabl_remove_index(g_argv, infos->current_index);
	init_infos(infos, 0);
}

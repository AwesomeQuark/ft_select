/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 17:45:48 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void handle_left(char ***args, t_infos *infos)
{
	args = NULL;
	if (infos->x != 0)
		infos->x--;
	else if (infos->current_index != 0)
	{
		infos->y--;
		infos->x = infos->max_x;
	}
	else
	{
		infos->x = infos->nb_args % infos->max_x;
		infos->y = infos->max_y;
	}
}

void handle_right(char ***args, t_infos *infos)
{
	args = NULL;
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

void	handle_up(char ***args, t_infos *infos)
{
	args = NULL;
	if (infos->y == 0)
	{
		infos->y = infos->max_y;
		infos->x--;
	}
	else
		infos->y--;
}

void	handle_down(char ***args, t_infos *infos)
{
	args = NULL;
	if (infos->y == infos->max_y)
	{
		infos->x++;
		infos->y = 0;
	}
	else if (infos->current_index + infos->max_x < infos->nb_args)
		infos->y++;
	else if (infos->current_index == infos->nb_args)
	{
		infos->x = 0;
		infos->y = 0;
	}
}

void handle_del(char ***args, t_infos *infos)
{
	if (tab_len(*args) == 1)
		end(1);
	if (infos->current_index == infos->nb_args - 1)
	{
		if (infos->x != 0)
			infos->x--;
		else
		{
			infos->x = infos->max_x - 1;
			infos->y--;
		}
	}
	infos->selected = realloc_int_tab(infos->current_index, infos->selected, 		infos->nb_args);
	*args = realloc_tabl_remove_index(*args, infos->current_index);
	init_infos(infos, *args, 0);
}
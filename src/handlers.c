/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:30:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 11:03:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void handle_left(char ***args, t_infos *infos)
{
	args = NULL;
	if (infos->x == 0)
	{
		infos->y--;
		infos->x = infos->max_x - 1;
	}
	else
		infos->x--;
}

void handle_right(char ***args, t_infos *infos)
{
	args = NULL;
	if (infos->x == (infos->max_x - 1))
	{
		infos->x = 0;
		infos->y++;
	}
	else
		infos->x++;
}

void	handle_down(char ***args, t_infos *infos)
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

void	handle_up(char ***args, t_infos *infos)
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
	if (infos->current_index == infos->nb_args)
		infos->y--;
	*args = realloc_tabl_remove_index(*args, infos->y);
	init_infos(infos, *args, 0);
}
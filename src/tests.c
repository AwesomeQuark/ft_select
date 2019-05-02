/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:45:34 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 12:01:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int test_left(char *buff, t_infos *infos)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68 && (infos->x > 0
	|| infos->y > 0))
		return (1);
	else
		return (0);
}

int test_right(char *buff, t_infos *infos)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67 && infos->current_index
	+ 1 < infos->nb_args)
		return (1);
	else
		return (0);
}

int test_up(char *buff, t_infos *infos)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65 && (infos->y > 0
	|| infos->x > 0))
		return (1);
	else
		return (0);
}

int test_down(char *buff, t_infos *infos)
{
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66 && (infos->y
	< infos->max_y || infos->x < infos->max_x - 1))
		return (1);
	else
		return (0);
}

int test_del(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 127 && buff[1] == 0)
		return (1);
	else
		return (0);
}
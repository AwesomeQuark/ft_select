/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:09 by conoel            #+#    #+#             */
/*   Updated: 2019/05/03 17:52:14 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_escape(char ***args, t_infos *infos)
{
	if (infos->selected)
		free(infos->selected);
	free_tab(*args);
	end(1);
}

void	handle_space(char ***args, t_infos *infos)
{
	args = NULL;
	infos->selected
	[infos->current_index] = !infos->selected[infos->current_index];
	if (infos->x != infos->max_x && infos->current_index != infos->nb_args - 1)
		infos->x++;
	else if (infos->current_index != infos->nb_args - 1)
	{
		infos->y++;
		infos->x = 1;
	}
	else
	{
		infos->x = 0;
		infos->y = 0;
	}
}

void	handle_enter(char ***args, t_infos *infos)
{
	int		i;

	i = 0;
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	while ((*args)[i])
	{
		if (infos->selected[i])
		{
			write(1, (*args)[i], ft_strlen((*args)[i]));
			write(1, " ", 1);
		}
		i++;
	}
	free(infos->selected);
	free_tab(*args);
	end(0);
}

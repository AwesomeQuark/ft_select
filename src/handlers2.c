/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:09 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 14:23:15 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void handle_escape(char ***args, t_infos *infos)
{
	args = NULL;
	infos = NULL;
	end(1);
}

void handle_space(char ***args, t_infos *infos)
{
	args = NULL;
	infos->selected[infos->current_index]
	= !infos->selected[infos->current_index];
}

void handle_enter(char ***args, t_infos *infos)
{
	args = NULL;
	infos->selected[infos->current_index]
	= !infos->selected[infos->current_index];
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:26 by conoel            #+#    #+#             */
/*   Updated: 2019/05/05 18:39:15 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	test_escape(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_space(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 32 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_enter(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 10 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_completion(char *buff, t_infos *infos)
{
	if (buff[0] == '\t' && buff[1] == 0)
	{
		if (!(infos->completion = malloc(sizeof(char))))
			end(0);
		infos->completion[0] = '\0';
		infos->found = infos->nb_args;
		return (1);
	}
	else
		return (0);
}

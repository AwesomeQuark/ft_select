/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:26 by conoel            #+#    #+#             */
/*   Updated: 2019/05/03 13:59:19 by conoel           ###   ########.fr       */
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

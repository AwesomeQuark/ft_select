/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:45:34 by conoel            #+#    #+#             */
/*   Updated: 2019/06/27 15:22:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	test_left(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		return (1);
	else
		return (0);
}

int	test_right(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		return (1);
	else
		return (0);
}

int	test_up(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		return (1);
	else
		return (0);
}

int	test_down(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		return (1);
	else
		return (0);
}

int	test_del(char *buff, t_infos *infos)
{
	infos = NULL;
	if ((buff[0] == 127 && buff[1] == 0)
		|| (buff[0] == 27 && buff[1] == 91 && buff[2] == 51))
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:26 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 11:13:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int test_escape(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 0)
		return (1);
	else
		return (0);
}
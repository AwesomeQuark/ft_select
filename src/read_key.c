/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:37:01 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 11:15:03 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_handlers g_handlers[] =
{
	{test_left, handle_left},
	{test_right, handle_right},
	{test_down, handle_down},
	{test_up, handle_up},
	{test_del, handle_del},
	{test_escape, handle_escape},
	{NULL, NULL}
};

int			read_key(char **args)
{
	char		buff[3];
	t_infos		infos;
	int			i;
	
	init_infos(&infos, args, 1);
	while (1)
	{
		i = 0;
		display(args, &infos);
		ft_bzero(buff, 3);
		read(0, buff, 3);
		if (buff[0] == 27 && buff[1] == 0)
			end(1);
		while (g_handlers[i].test != NULL)
		{
			if (g_handlers[i].test(buff, &infos))
				g_handlers[i].handler(&args, &infos);
			i++;
		}
	}
	return (0);
}
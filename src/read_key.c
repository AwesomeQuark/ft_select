/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:37:01 by conoel            #+#    #+#             */
/*   Updated: 2019/06/27 15:23:12 by conoel           ###   ########.fr       */
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
	{test_space, handle_space},
	{test_enter, handle_enter},
	{test_completion, handle_completion},
	{NULL, NULL}
};

int			read_key(void)
{
	char		buff[4];
	int			i;

	init_infos(&g_infos, 1);
	while (1)
	{
		i = 0;
		ft_bzero(buff, 4);
		display(&g_infos);
		read(0, buff, 3);
		while (g_handlers[i].test != NULL)
		{
			if (g_handlers[i].test(buff, &g_infos))
			{
				g_handlers[i].handler(&g_infos);
				break ;
			}
			i++;
		}
	}
	return (0);
}

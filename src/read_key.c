/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:37:01 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 20:23:55 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	display(char **choices, t_infos *infos)
{
	int				i;
	struct winsize	w;

	i = 0;
	ioctl(0, TIOCGWINSZ, &w);
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
	while (choices[i])
	{
		if (i == infos->y)
			ft_printf("\033[41m\033[30m%-*s\n\033[0m", infos->max_len, choices[i++]);
		else
			ft_printf("%-*s\n", infos->max_len, choices[i++]);
	}
	ft_printf("%d %d", infos->x, infos->y);
}

int		read_key(char **args)
{
	char		buff[3];
	t_infos		infos;

	infos.x = 0;
	infos.y = 0;
	infos.max_x = 0;
	infos.max_y = tab_len(args) - 1;
	infos.max_len = get_longer(args);
	while (1)
	{
		ft_bzero(buff, 3);
		read(0, buff, 3);
		if (buff[0] == 12 && buff[1] == 10)
			tputs(tgetstr("cl", NULL), 0, ft_putchar);
		if (buff[0] == 27 && buff[1] == 0)
			return (1);
		if (buff[0] == 127 && buff[1] == 0)
			args = realloc_tabl_remove_index(args, infos.y);
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65 && infos.y > 0)
			infos.y--;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66 && infos.y < infos.max_y)
			infos.y++;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68 && infos.x > 0)
			infos.x--;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67 && infos.x < infos.max_x)
			infos.x++;
		display(args, &infos);
		printf("%d %d %d\n", buff[0], buff[1], buff[2]);
	}
	return (0);
}
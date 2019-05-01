/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 13:37:01 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 19:21:56 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	display(char **choices, int x, int y)
{
	choices = NULL;
	x = 0;
	y = 0;
}

int		read_key(char **args)
{
	char		buff[3];
	int			y;
	int			x;

	x = 0;
	y = 0;
	while (1)
	{
		ft_bzero(buff, 3);
		read(0, buff, 3);
		//printf("%d %d %d\n", buff[0], buff[1], buff[2]);
		if (buff[0] == 12 && buff[1] == 10)
			tputs(tgetstr("cl", NULL), 0, ft_putchar);
		if (buff[0] == 27 && buff[1] == 0)
			return (1);
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65 && y > 0)
			y--;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
			y++;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67 && x > 0)
			x++;
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
			x--;
		//if (buff[0] == )
		display(args, x, y);
		tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putchar);
	}
	return (0);
}
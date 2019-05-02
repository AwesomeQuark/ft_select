/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:46:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/02 11:04:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void display(char **choices, t_infos *infos)
{
	int i;

	i = 0;
	infos->current_index = infos->x + (infos->y * infos->max_x);
	tputs(tgetstr("cl", NULL), 0, ft_putchar);
	while (choices[i])
	{
		if (i == infos->current_index)
			ft_printf("\033[41m\033[30m%-*s\033[0m", infos->max_len,
					  choices[i++]);
		else
			ft_printf("%-*s", infos->max_len, choices[i++]);
		if (i % infos->max_x == 0)
			write(1, "\n", 1);
	}
	ft_printf("%d %d", infos->x, infos->y);
}

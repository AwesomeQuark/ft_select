/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:46:42 by conoel            #+#    #+#             */
/*   Updated: 2019/05/03 13:24:58 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	display(char **choices, t_infos *infos)
{
	int i;

	i = 0;
	init_infos(infos, choices, 0);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	tputs(tgoto(tgetstr("cm", NULL), infos->original_x, infos->original_y),
		1, ft_putchar_stdout);
	while (choices[i])
	{
		if (infos->selected[i] == 1 && i == infos->current_index)
			dprintf(0, "\033[7m\033[4m%-*s\033[0m", infos->max_len,
				choices[i++]);
		else if (infos->selected[i] == 1)
			dprintf(0, "\033[7m%-*s\033[0m", infos->max_len,
				choices[i++]);
		else if (i == infos->current_index)
			dprintf(0, "\033[4m%-*s\033[0m", infos->max_len,
				choices[i++]);
		else
			dprintf(0, "%-*s", infos->max_len, choices[i++]);
		if (i % infos->max_x == 0)
			write(0, "\n", 1);
	}
}

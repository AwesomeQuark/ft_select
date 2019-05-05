/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:09 by conoel            #+#    #+#             */
/*   Updated: 2019/05/05 16:30:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		handle_escape(t_infos *infos)
{
	if (infos->selected)
		free(infos->selected);
	end(1);
}

void		handle_space(t_infos *infos)
{
	infos->selected
	[infos->current_index] = !infos->selected[infos->current_index];
	if (infos->x != infos->max_x && infos->current_index != infos->nb_args - 1)
		infos->x++;
	else if (infos->current_index != infos->nb_args - 1)
	{
		infos->y++;
		infos->x = 1;
	}
	else
	{
		infos->x = 0;
		infos->y = 0;
	}
}

void		handle_enter(t_infos *infos)
{
	int		i;

	i = 0;
	tputs(tgetstr("cl", NULL), 1, ft_putchar_stdout);
	while (g_argv[i])
	{
		if (infos->selected[i])
		{
			if (i != 0)
				write(1, " ", 1);
			write(1, g_argv[i], ft_strlen(g_argv[i]));
		}
		i++;
	}
	free(infos->selected);
	end(0);
}

static int	find_in_args(t_infos *infos)
{
	size_t	i;
	int		found;

	i = 0;
	found = 0;
	while (g_argv[i])
	{
		if (ft_strncmp(g_argv[i], infos->completion,
			ft_strlen(infos->completion)) == 0)
		{
			found++;
			if (found == 1)
			{
				infos->x = i % infos->max_x;
				infos->y = i / infos->max_x;
				display(infos, 0);
			}
		}
		i++;
	}
	return (found);
}

void		handle_completion(t_infos *infos)
{
	char	buff[4];
	char	*tmp;

	while (1)
	{

		ft_bzero(buff, 4);
		read(0, buff, 3);
		tmp = infos->completion;
		if (!(infos->completion = ft_strjoin(infos->completion, buff)))
			end(0);
		free(tmp);
		infos->found = find_in_args(infos);
		if (test_escape(buff, infos) || infos->found < 2)
		{
			free(infos->completion);
			infos->completion = NULL;
			return ;
		}

	}
}

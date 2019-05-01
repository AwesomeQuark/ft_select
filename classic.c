/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:43:46 by mbonati           #+#    #+#             */
/*   Updated: 2019/04/24 16:25:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_max_len(t_file *dir)
{
	size_t		max;

	max = 0;
	while (dir)
	{
		if (ft_strlen(dir->name) > max)
			max = ft_strlen(dir->name);
		dir = dir->next;
	}
	return ((int)max + 1);
}

static void	c_display(t_file *file, char *opt, int max_len)
{
	if (opt[G_COLOR] == '1')
		color(file);
	ft_printf("%-*s\033[0m", max_len, file->name);
}

void		classic(t_file *dir, char *opt, t_spaces *space)
{
	int				max_len;
	struct winsize	w;
	int				nb_column;
	int				index_column;

	ioctl(0, TIOCGWINSZ, &w);
	max_len = get_max_len(dir);
	nb_column = w.ws_col / max_len;
	index_column = -1;
	while (dir)
	{
		if (++index_column == nb_column)
		{
			index_column = 0;
			write(1, "\n", 1);
		}
		c_display(dir, opt, max_len);
		if (opt[I_INODE] == '1')
			ft_printf(" %*s\n", space->inode, dir->inode);
		if (opt[S_BLOCK] == '1')
			ft_printf(" %*d\n", space->blocks, dir->blocks);
		dir = dir->next;
	}
}

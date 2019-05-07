/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 11:12:26 by conoel            #+#    #+#             */
/*   Updated: 2019/05/07 16:34:21 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	test_escape(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 27 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_space(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 32 && buff[1] == 0)
		return (1);
	else
		return (0);
}

int	test_enter(char *buff, t_infos *infos)
{
	infos = NULL;
	if (buff[0] == 10 && buff[1] == 0)
		return (1);
	else
		return (0);
}

static char *common_base(char **words)
{
	size_t	size_identical;
	size_t	i;
	char	identical;
	char	*ret;

	identical = 1;
	size_identical = 1;
	while (identical)
	{
		i = 0;
		while (words[i])
		{
			if (ft_strncmp(words[i], words[0], size_identical) != 0)
			{
				identical = 0;
				break;
			}
			i++;
		}
		size_identical++;
	}
	ret = ft_memdup(words[1], size_identical - 2);
	return (ret);
}

int	test_completion(char *buff, t_infos *infos)
{
	if (buff[0] == '\t' && buff[1] == 0)
	{
		if (!(infos->completion = common_base(g_argv)))
			end(0);
		infos->found = infos->nb_args;
		return (1);
	}
	else
		return (0);
}

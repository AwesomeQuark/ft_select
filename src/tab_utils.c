/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:51:24 by conoel            #+#    #+#             */
/*   Updated: 2019/05/01 20:20:55 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static size_t	tabl_size(char **tabl)
{
	size_t	i;

	i = 0;
	while (tabl && tabl[i])
		i++;
	return (i);
}

char			**realloc_tabl_remove_index(char **tabl, size_t index)
{
	char	**ret;
	size_t	size;
	size_t	i;
	size_t	j;

	size = tabl_size(tabl);
	if (!(ret = malloc(sizeof(char *) * size)))
		return (0);
	ret[size - 1] = NULL;
	i = 0;
	j = 0;
	while (ret && i < size - 1)
	{
		if (i == index)
			j++;
		ret[i] = ft_strdup(tabl[j]);
		i++;
		j++;
	}
	free_tab(tabl);
	return (ret);
}

char			**copy_tabl(size_t size, char **tabl)
{
	char	**ret;
	size_t	i;

	if (!(ret = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	ret[size] = NULL;
	i = 0;
	while (tabl && i < size)
	{
		ret[i] = ft_strdup(tabl[i]);
		i++;
	}
	return (ret);
}

int					get_longer(char **tabl)
{
	int	i;
	size_t max;

	i = 0;
	max = 0;
	while (tabl[i])
	{
		if (ft_strlen(tabl[i]) > max)
			max = ft_strlen(tabl[i]);
		i++;
	}
	return (max);
}

int						tab_len(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:38:13 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/11 18:21:16 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include "../../headers/minirt.h"

static char *get_id(char *str)
{
    char *id;
    int i;
    int j;
    int len;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    j = i;
    len = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
    {
        i++;
        len++;
    }
    id = malloc((len + 1) * sizeof(char));
    if (!id)
        return (NULL);
    i = j;
    j = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
        id[j++] = str[i++];
    id[j] = '\0';
    return (id);
}

static char **get_ids(char **data, int len)
{
    char **ids;
    char *id;
    int i;

    ids = malloc((len + 1) * sizeof(char *));
    if (!ids)
        return (NULL);
    i = 0;
    while (data[i])
    {
        id = get_id(data[i]);
        if (!id)
            return (free_split(ids), NULL);
        ids[i] = id;
        i++;
    }
    return (ids);
}

int	set_data(char **data, t_scene *scene)
{
	int		data_len;
	char	**ids;

	data_len = ft_splitlen(data);
	ids = get_ids(data, data_len);
	if (!ids)
		return (1);
	if (ft_malloc_scene(ids, scene))
		return (free_split(ids), 1);
	if (put_data(scene, ids, data))
		return (free_split(ids), 1);
	free_split(ids);
	return (0);
}

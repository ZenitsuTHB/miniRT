/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:05:09 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/16 18:53:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parser.h"
#include <stdlib.h>

t_ambient	*new_ambient(void)
{
	t_ambient	*new;

	new = malloc(sizeof(t_ambient));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	return (new);
}

t_camera	*new_camera(void)
{
	t_camera	*new;

	new = malloc(sizeof(t_camera));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	return (new);
}

t_light	*new_light(void)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (error_parser(YEL, MSG_MEM), NULL);
	return (new);
}

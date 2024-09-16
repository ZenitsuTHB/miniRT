/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:11:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/16 18:51:59 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"
# include "macros.h"

int			set_data(t_scene *scene, char *str);

int			set_ambient(t_ambient *amb, char *str);
int			set_camera(t_camera *cam, char *str);
int			set_light(t_light *light, char *str);

int			set_sphere(t_sphere *sphere, char *str);
int			set_plane(t_plane *plane, char *str);
int			set_cylinder(t_cylinder *cyl, char *str);
int			set_cone(t_cone *cone, char *str);

t_ambient	*new_ambient(void);
t_camera	*new_camera(void);
t_light		*new_light(void);

void		error_parser(char *color, char *msg);
void		free_split(char **split);
int			ft_splitlen(char **split);
double		ft_strtod(char *str, char **error);

#endif

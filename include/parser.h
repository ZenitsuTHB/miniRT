/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:11:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/02 00:35:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

int			set_data(t_scene *scene, char *str);

t_ambient	*set_ambient(char *str, int *error);
t_camera	*set_camera(char *str, int *error);
t_light		*set_light(char *str, int *error);

void		add_sphere(t_sphere **sphere, char *str, int *error);
void		add_plane(t_plane **plane, char *str, int *error);
void		add_cylinder(t_cylinder **cyl, char *str, int *error);
void		add_cone(t_cone **cone, char *str, int *error);

void		*new_setup(int type);
t_sphere	*new_sphere(t_sphere *prev);
t_plane		*new_plane(t_plane *prev);
t_cylinder	*new_cylinder(t_cylinder *prev);
t_cone		*new_cone(t_cone *prev);

int			set_color(char *str, t_rgb *rgb);
int			set_pos(char *str, t_vec3 *pos);
int			set_normal(char *str, t_vec3 *normal);

int         error_parser(char *color, char *msg);
void		free_split(char **split);
int			ft_splitlen(char **split);
double		ft_strtod(char *str, char **error);
int			ft_atoi_error(const char *str, int *error);

#endif

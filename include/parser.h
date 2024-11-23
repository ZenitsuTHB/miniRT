/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:11:18 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/11/23 13:30:22 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "struct.h"
# include "minirt.h"

int			set_data(t_scene *scene, char *str);

void		set_ambient(t_scene *scene, char *data, int *error);
void		set_camera(t_scene *scene, char *data, int *error);
void		set_light(t_scene *scene, char *data, int *error);
void		set_object(t_scene *scene, char *id, char *data, int *error);

t_sphere	*get_sphere(char *data, int *error);
t_plane		*get_plane(char *data, int *error);
t_cylinder	*get_cylinder(char *data, int *error);
t_cube		*get_cube(char *data, int *error);

int			set_color(char *str, t_rgb *rgb);
int			set_pos(char *str, t_vec3 *pos);
int			set_normal(char *str, t_vec3 *normal);

void		error_parser(char *color, char *msg);
void		free_split(char **split);
int			ft_splitlen(char **split);
double		ft_strtod(char *str, char **error);
int			ft_atoi_error(const char *str, int *error);

int			get_angle(double height, double radius, double *angle);

#endif

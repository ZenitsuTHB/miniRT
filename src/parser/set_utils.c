/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:09:15 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/21 14:38:19 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"

double	parse_digits(char *str, char **error)
{
	double	res;
	double	div;
	int		decimal;

	res = 0.0;
	div = 1.0;
	decimal = 0;
	while (*str)
	{
		if (ft_isdigit(*str) && decimal)
		{
			div *= 10.0;
			res += (*str - '0') / div;
		}
		else if (ft_isdigit(*str) && !decimal)
			res = res * 10.0 + *str - '0';
		else if (*str == '.' && !decimal)
			decimal = 1;
		else
			break ;
		str++;
	}
	*error = str;
	return (res);
}

char	*parse_sign(char *str, int *sign)
{
	*sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			*sign = -1;
	return (str);
}

double	ft_strtod(char *str, char **error)
{
	double	res;
	int		sign;

	str = parse_sign(str, &sign);
	res = parse_digits(str, error);
	return (res * sign);
}

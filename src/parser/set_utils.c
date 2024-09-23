/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:09:15 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/09/23 17:35:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/libft/libft.h"

static double	parse_digits(char *str, char **error)
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

static char	*parse_sign(char *str, int *sign)
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

int	ft_atoi_error(const char *str, int *error)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			*error = 1;
			break ;
		}
		res = res * 10 + str[i++] - '0';
	}
	return (res * sign);
}

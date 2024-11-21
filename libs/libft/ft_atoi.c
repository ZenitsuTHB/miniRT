/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:39:23 by avolcy            #+#    #+#             */
/*   Updated: 2024/11/21 22:41:05 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *str)
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
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
	}
	return (res * sign);
}

double	ft_atod(const char *str, double res, double doub, int i)
{
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] && ft_isdigit(str[i])) || str[i] == '.')
	{
		if (str[i] == '.')
		{
			i++;
			break ;
		}
		res = res * 10 + str[i++] - '0';
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res += (str[i++] - '0') * doub;
		doub *= 0.1;
	}
	if (str[0] == '-')
		res *= -1;
	return (res);
}

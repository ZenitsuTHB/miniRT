/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 20:26:22 by avolcy            #+#    #+#             */
/*   Updated: 2024/03/11 19:09:07 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int v)
{
	if (v >= 32 && v <= 126)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:38:57 by avolcy            #+#    #+#             */
/*   Updated: 2024/04/27 19:00:46 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

  if (!s1)
    return (NULL);
	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
//	ft_strlcpyptr, s1, (ft_strlen(s1) + 1) * sizeof(char));

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:38:38 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/10/03 14:39:37 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(char c, char *set)
{
	int	i;

	if (!set || !set[0])
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_cnt_word(const char *s, char *set)
{
	int		i;
	int		word;
	int		count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (check_space(s[i], set))
			count = 0;
		else if (count == 0)
		{
			count = 1;
			word++;
		}
		i++;
	}
	return (word);
}

static void	ft_free_array(char **res, int i)
{
	while (i--)
	{
		free(res[i]);
	}
	free(res);
}

static char	**ft_create(char const *s, char *set, char **res)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (i > 0 && !check_space(s[i], set) && check_space(s[i - 1] , set))
			start = i;
		if (!check_space(s[i], set) && (check_space(s[i + 1], set) || s[i + 1] == '\0'))
		{
			res[j] = ft_substr(s, start, i - start + 1);
			if (!res[j])
			{
				ft_free_array(res, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_splitset(char const *s, char *set)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_cnt_word(s, set) + 1));
	if (!result)
		return (NULL);
	result = ft_create(s, set, result);
	return (result);
}
/*
int main ()
{
	char **test;
	int i = 0;

	test = ft_splitset("   bonjou,   koman  nou ye   ", " 	\t");
	while (test[i])
	{
		printf("%d _%s_\n", i, test[i]);
		i++;
	}
	return (0);
}*/

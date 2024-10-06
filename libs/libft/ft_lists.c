/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:31:03 by avolcy            #+#    #+#             */
/*   Updated: 2024/10/04 22:04:58 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(void *lst, void *new)
{
	void	**aux;
	
	if (!lst || !new)
		return ;
	aux = *(void **)lst;
	if(!aux)
	{
		aux = new;
		return ;
	}
	while (*aux)
		aux = *aux;
	*aux = new;
}

void	ft_lstadd_front(void *lst, void *new)
{
	void	**aux;

	if (!lst || !new)
		return ;
	aux = *(void **)lst;
	ft_lstadd_back(&new, aux);
	aux = new;
}

void	lst_clear(void *list, void (*del)(void *))
{
	void *tmp;
	void **aux;

	if (!list || !del)
		return ;
	aux = *(void **)list;
	while (aux)
	{
		tmp = *aux;
		del(aux);
		free(aux);
		aux = tmp;
	}
	*(void **)list = NULL;
}

void	lst_for_each(void *list, void (*func)(void *))
{
	void	**aux;

	if (!list || !func)
		return ;
	aux = list;
	while (aux)
	{
		func(aux);
		aux = *aux;
	}
}


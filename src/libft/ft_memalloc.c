/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:12:18 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 14:24:56 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	tab = NULL;
	tab = (char *)malloc(sizeof(char) * size);
	if (tab != NULL)
	{
		i = 0;
		while (i < size)
		{
			tab[i] = 0;
			i++;
		}
	}
	return ((void *)tab);
}

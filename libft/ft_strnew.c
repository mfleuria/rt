/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:29:01 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 14:05:03 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	tab = NULL;
	tab = (char *)malloc(sizeof(char) * size + 1);
	if (tab != NULL)
	{
		i = 0;
		while (i < size)
		{
			tab[i] = '\0';
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}

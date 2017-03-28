/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:30:25 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 14:05:46 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tronc;
	size_t	i;

	tronc = NULL;
	if (s != NULL)
	{
		tronc = (char *)malloc(sizeof(char) * (len + 1));
		if (tronc != NULL)
		{
			i = 0;
			while (i < len)
			{
				tronc[i] = s[start + i];
				i++;
			}
			tronc[i] = '\0';
		}
	}
	return (tronc);
}

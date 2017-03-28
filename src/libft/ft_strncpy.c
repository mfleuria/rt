/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:38:32 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 13:39:33 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		if (src[i] == '\0')
			dst[i] = '\0';
		dst[i] = src[i];
		i++;
	}
	if (i < n)
		ft_bzero(dst + i, n - i);
	return (dst);
}

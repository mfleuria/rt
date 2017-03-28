/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:07:31 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 12:01:59 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dsst;
	char	*srrc;
	int		i;

	srrc = (char *)src;
	dsst = (char *)dst;
	i = len;
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (i > 0)
		{
			dsst[i - 1] = srrc[i - 1];
			i--;
		}
		return (dst);
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:32:51 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 12:54:55 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	t_src;
	size_t	t_dst;
	int		i;
	int		j;
	int		stop;

	t_dst = ft_strlen(dst);
	t_src = ft_strlen(src);
	j = 0;
	stop = size - t_dst - 1;
	i = t_dst;
	while (src[j] && j < stop)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[j + i] = '\0';
	if (size <= t_dst)
		return (t_src + size);
	return (t_src + t_dst);
}

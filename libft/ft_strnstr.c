/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:15:44 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 10:54:36 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!(s2[i]))
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (i + j < n && s2[j + 1] == '\0')
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (0);
}

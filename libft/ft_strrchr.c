/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:52:36 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 13:45:24 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	while (s1[i] != '\0')
		i++;
	while (i > 0)
	{
		if (s1[i] == c)
			return (s1 + i);
		i--;
	}
	if (s1[i] == c)
		return (s1 + i);
	return (0);
}

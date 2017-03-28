/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:24:05 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/16 18:36:32 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		cp_str(char *s1, char *str, int j)
{
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	return (j);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss1;
	char	*str;
	int		j;
	int		k;

	ss1 = (char *)s1;
	str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		str = (char *)ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (str != NULL)
		{
			j = 0;
			k = 0;
			j = cp_str(ss1, str, j);
			while (s2[k] != '\0')
			{
				str[j] = s2[k];
				k++;
				j++;
			}
			str[j] = '\0';
		}
	}
	return (str);
}

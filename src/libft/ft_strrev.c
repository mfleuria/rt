/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:24:14 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 17:36:27 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	a;
	int		i;
	int		j;

	if (str)
	{
		i = ft_strlen(str);
		i--;
		j = 0;
		while (i > j)
		{
			a = str[i];
			str[i] = str[j];
			str[j] = a;
			i--;
			j++;
		}
	}
	return (str);
}

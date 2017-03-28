/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 15:08:53 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 17:36:21 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrev(char *str, size_t n)
{
	char	a;
	size_t	i;

	i = 0;
	if (n <= 0)
		return (str);
	if (str && n < ft_strlen(str))
	{
		n--;
		while (i < n)
		{
			a = str[i];
			str[i] = str[n];
			str[n] = a;
			i++;
			n--;
		}
	}
	return (str);
}

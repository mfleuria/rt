/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncarac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:55:18 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 18:06:30 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncarac(char *str, char c, size_t n)
{
	size_t i;

	if (str && (n < ft_strlen(str)))
	{
		i = 0;
		while (i < n)
		{
			str[i] = c;
			i++;
		}
	}
	return (str);
}

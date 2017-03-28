/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcarac.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:02:27 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/17 12:26:32 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcarac(char *str, char c)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			str[i] = c;
			i++;
		}
	}
	return (str);
}

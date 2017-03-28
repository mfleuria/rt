/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:26:06 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 13:44:50 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;

	tab = NULL;
	if (s && f)
	{
		tab = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (tab != NULL)
		{
			i = 0;
			while (s[i])
			{
				tab[i] = f(i, s[i]);
				i++;
			}
			tab[i] = '\0';
		}
	}
	return (tab);
}

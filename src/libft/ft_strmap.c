/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:25:27 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 13:45:44 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				tab[i] = f(s[i]);
				i++;
			}
			tab[i] = '\0';
		}
	}
	return (tab);
}

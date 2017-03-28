/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:11:02 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 14:02:46 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = 0;
	tab = NULL;
	tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (tab != NULL)
	{
		while (s[i] != '\0')
		{
			tab[i] = s[i];
			i++;
		}
		tab[i] = s[i];
	}
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:41:51 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/16 18:31:24 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_compteur(char const *s, int *k, int *j)
{
	while (s[*j] != '\0')
	{
		if (s[*j] != ' ' && s[*j] != '\n' && s[*j] != '\t')
		{
			*j = *j + 1;
			*k = *j;
		}
		else
			*j = *j + 1;
	}
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	ft_compteur(s, &k, &j);
	if (j == 0 || ft_strsub(s, i, k - i) == NULL)
	{
		str = ft_strdup("");
		return (str);
	}
	return (ft_strsub(s, i, k - i));
}

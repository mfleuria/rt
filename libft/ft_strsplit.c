/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:20:04 by jeexpert          #+#    #+#             */
/*   Updated: 2016/03/16 15:32:38 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_len_malloc(char const *s, char c, int *i, int *j)
{
	while (s[*i] != '\0')
	{
		while (s[*i] == c)
			*i = *i + 1;
		if (s[*i] != c && s[*i] != '\0')
		{
			*j = *j + 1;
			while (s[*i] != c && s[*i] != '\0')
				*i = *i + 1;
		}
	}
}

static void	ft_creat_tab(char const *s, char **str, char c, int *j)
{
	int i;
	int len;

	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i + len] != c && s[i + len] != '\0')
				len++;
			str[*j] = ft_strsub(s, i, len);
			*j = *j + 1;
		}
		i = i + len;
	}
	str[*j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = NULL;
	if (s != NULL)
	{
		ft_len_malloc(s, c, &i, &j);
		str = (char **)malloc(sizeof(char *) * j + 1);
		if (str)
		{
			j = 0;
			ft_creat_tab(s, str, c, &j);
		}
	}
	return (str);
}

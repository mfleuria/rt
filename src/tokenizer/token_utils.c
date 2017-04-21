#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../../header/includes.h"

char			*ft_strcln(char *str)
{
	int			cpt;
	int			s_cpt;
	char		*swap;

	cpt = 0;
	s_cpt = 0;
	swap = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_bzero(swap, ft_strlen(str) + 1);
	while (str[cpt] != '\0')
	{
		if ((str[cpt] >= 48 && str[cpt] <= 57)
			|| str[cpt] == '.' || str[cpt] == ',')
		{
			swap[s_cpt] = str[cpt];
			s_cpt++;
		}
		cpt++;
	}
	ft_strcpy(str, swap);
	free(swap);
	return (str);
}

int				ft_len_tab(char **tab)
{
	int			cpt;

	cpt = 0;
	while (tab[cpt] != NULL)
		cpt++;
	return (cpt);
}

int				ft_strchrstr(char *str, char *elem)
{
	int			cpt;
	int			i;

	cpt = 0;
	while (str[cpt] != '\n' && str[cpt] != '\0')
	{
		i = 0;
		while (str[cpt] != elem[0] && str[cpt] != '\n' && str[cpt] != '\0')
			cpt++;
		while (str[cpt + i] == elem[i] && elem[i] != '\0'
		&& str[cpt + i] != '\n' && str[cpt + i] != '\0')
		{
			i++;
			if (elem[i] == '\0')
				return (0);
		}
		cpt++;
	}
	return (-1);
}

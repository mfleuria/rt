/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:11:57 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/16 18:38:59 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		test_taille(int nb)
{
	int taille;

	if (nb == 0)
		return (1);
	taille = 0;
	while (nb != 0)
	{
		taille++;
		nb = nb / 10;
	}
	return (taille);
}

static	int		test_signe(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static	void	move_to_str(char *string, int n, int i, int j)
{
	if (n == 0)
	{
		i--;
		string[i] = '0';
	}
	while (n != 0)
	{
		i--;
		string[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (j == 1)
	{
		i--;
		string[i] = '-';
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	str = NULL;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (test_taille(n) + test_signe(n) + 1));
	if (str != NULL)
	{
		i = 0;
		j = test_signe(n);
		if (n < 0)
			n = n * -1;
		while (i < (test_taille(n) + j))
			i++;
		str[i] = '\0';
		move_to_str(str, n, i, j);
	}
	return (str);
}

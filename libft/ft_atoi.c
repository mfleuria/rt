/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:09:28 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 15:17:16 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int out;
	int j;

	j = 0;
	i = 0;
	out = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||\
			str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
		j++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		i++;
	}
	if (str[j] == '-')
		out = out * -1;
	return (out);
}

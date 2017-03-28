/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:09:00 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/14 14:39:00 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (del)(void *, size_t))
{
	t_list *temp;
	t_list *temp1;

	if (*alst != NULL && del != NULL)
	{
		temp = *alst;
		while (temp)
		{
			temp1 = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp1;
		}
		*alst = NULL;
	}
}

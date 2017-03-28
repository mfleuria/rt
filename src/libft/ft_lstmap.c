/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:18:08 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/11 11:39:33 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*compt;
	t_list	*stock;

	newlst = NULL;
	if (lst != NULL && f != NULL)
	{
		newlst = f(lst);
		compt = newlst;
		while (lst->next)
		{
			lst = lst->next;
			stock = f(lst);
			if (stock == NULL)
				return (0);
			compt->next = stock;
			compt = compt->next;
		}
	}
	return (newlst);
}

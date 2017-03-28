/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 08:33:02 by jeexpert          #+#    #+#             */
/*   Updated: 2015/12/15 17:19:40 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		if (content != NULL)
		{
			new->content = (void *)malloc(sizeof(char) * content_size);
			if (new->content != NULL)
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
				new->content_size = 0;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	return (new);
}

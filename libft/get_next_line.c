/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:34:03 by jeexpert          #+#    #+#             */
/*   Updated: 2016/03/15 09:06:55 by jeexpert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_index	*check_fd(int fd, t_index **list)
{
	t_index	*tmp;

	if (*list == NULL)
	{
		if (!(*list = (t_index *)malloc(sizeof(t_index))))
			return (NULL);
		(*list)->fd = fd;
		(*list)->str = NULL;
		(*list)->next = NULL;
		return (*list);
	}
	tmp = *list;
	while (tmp->fd != fd && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->fd != fd && tmp->next == NULL)
	{
		if (!(tmp->next = (t_index *)malloc(sizeof(t_index))))
			return (NULL);
		tmp = tmp->next;
		tmp->fd = fd;
		tmp->str = NULL;
		tmp->next = NULL;
	}
	return (tmp);
}

static void		creat_line3(char **line, char *bf, char *c, t_index *list)
{
	char *tmp3;
	char *tmp2;
	char *tmp;

	tmp3 = ft_strsub(bf, 0, (c - bf));
	tmp = ft_strjoin(*line, tmp3);
	tmp2 = ft_strsub(bf, (c - bf) + 1, (ft_strlen(bf) - (c - bf) + 1));
	free(*line);
	free(tmp3);
	free(bf);
	*line = tmp;
	list->str = tmp2;
}

static int		creat_line1(char **line, t_index *list, int ret, char *bf)
{
	char	*c;
	char	*tmp;
	char	*tmp2;

	while ((ret = read(list->fd, bf, BUFF_SIZE)))
	{
		bf[ret] = '\0';
		if ((c = ft_strchr(bf, '\n')))
		{
			creat_line3(line, bf, c, list);
			return (1);
		}
		else
		{
			tmp2 = ft_strsub(bf, 0, ft_strlen(bf));
			tmp = ft_strjoin(*line, tmp2);
			free(*line);
			free(tmp2);
			*line = tmp;
		}
	}
	return ((*line[0] != '\0') ? 1 : 0);
}

static int		creat_line(char **line, t_index *list, char *buff)
{
	char	*tmp;
	char	*tmp2;
	char	*chr;

	if (list->str != NULL)
	{
		if ((chr = ft_strchr(list->str, '\n')))
		{
			tmp = ft_strjoin(*line, ft_strsub(list->str, 0, (chr - list->str)));
			tmp2 = ft_strsub(list->str, (chr - list->str) + 1,\
					(ft_strlen(list->str) - (chr - list->str) - 1));
			free(*line);
			free(list->str);
			free(buff);
			*line = tmp;
			list->str = tmp2;
			return (1);
		}
		free(*line);
		*line = list->str;
		list->str = NULL;
	}
	return ((creat_line1(line, list, 1, buff) ? 1 : 0));
}

int				get_next_line(int const fd, char **line)
{
	static t_index	*list = NULL;
	t_index			*tmp;
	int				ret;
	char			*buff;

	if (fd < 0 || !(buff = ft_strnew(BUFF_SIZE + 1)) || line == 0)
		return (-1);
	if ((ret = read(fd, buff, 0) == -1))
	{
		free(buff);
		return (-1);
	}
	if (!(tmp = check_fd(fd, &list)))
	{
		free(buff);
		return (-1);
	}
	*line = ft_strnew(0);
	if (creat_line(line, tmp, buff))
		return (1);
	free(*line);
	*line = NULL;
	return (0);
}

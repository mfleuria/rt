#***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeexpert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 17:10:15 by jeexpert          #+#    #+#              #
#    Updated: 2016/03/15 08:51:31 by jeexpert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	 ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
	 ft_lstmap.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	 ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c\
	 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
	 ft_puttab.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
	 ft_strdup.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	 ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnew.c\
	 ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	 ft_tolower.c ft_toupper.c ft_lstnew.c ft_strequ.c ft_strnequ.c ft_debug.c\
	 ft_strcarac.c ft_strncarac.c ft_strrev.c ft_strnrev.c ft_atof.c ft_putfnbr.c \
	 get_next_line.c

OBJS = $(SRC:.c=.o)

HEAD = ./includes/

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

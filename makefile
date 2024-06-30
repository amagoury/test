# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aishamagoury <aishamagoury@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 16:37:12 by aishamagour       #+#    #+#              #
#    Updated: 2024/06/24 21:35:05 by aishamagour      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	 push_swap

SRCS		=   parse1.c error.c\
				parse2.c main.c\
				sorting.c moves1.c\
				moves2.c radix.c\
				
				
		

OBJS 		=	$(SRCS:.c=.o)

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3

LIBFT = libft/libft.a


all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC)	$(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)

%.o: %.c
	$(CC)	-c $(CFLAGS) $< -o $@

clean :
	$(MAKE) -C libft clean
	rm -f $(OBJS)
		
fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re
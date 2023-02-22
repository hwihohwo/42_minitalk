# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 08:42:20 by marvin            #+#    #+#              #
#    Updated: 2023/02/22 08:42:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = server
CC						= cc
SRCS                    = main.c
OBJS                    = $(SRCS:%.c=%.o)
FLAGS                   = -Wall -Wextra -Werror

$(NAME)     :   $(OBJS)
	@$(MAKE) -C ./../libft/
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -L ./../libft/ -lft -I .
	mv ./$(NAME) ./../
all :   $(NAME)
clean   :
	rm -f $(OBJS)
	@$(MAKE) -C ./../libft/ clean
fclean  :   clean
	rm -f ./../$(NAME)
	@$(MAKE) -C ./../libft/ fclean
re  :   fclean all
.PHONY  :   all clean fclean re

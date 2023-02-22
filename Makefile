# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 09:48:49 by marvin            #+#    #+#              #
#    Updated: 2023/02/22 09:48:49 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME                    = server client
CC						= cc
FLAGS                   = -Wall -Wextra -Werror

$(NAME)     :   $(OBJS)
	@$(MAKE) -C ./server_srcs
	@$(MAKE) -C ./client_srcs
all :   $(NAME)
clean   :
	@$(MAKE) -C ./server_srcs/ clean
	@$(MAKE) -C ./client_srcs/ clean
fclean  :   clean
	@$(MAKE) -C ./server_srcs/ fclean
	@$(MAKE) -C ./client_srcs/ fclean
re  :   fclean all
.PHONY  :   all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/07/06 19:24:03 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:		
			make -C ./libft/
			cp ./libft/libft.a ./libft.a
			@echo "libft done"

clean:		
			make clean -C ./libft/

fclean:		clean
			make fclean -C ./libft/

re:			fclean all

.PHONY:		all clean fclean re
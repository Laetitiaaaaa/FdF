# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llejeune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 15:32:45 by llejeune          #+#    #+#              #
#    Updated: 2019/01/23 15:52:22 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \

FLAG1 = -I /usr/local/include

FLAG2 = -L /usr/local/lib/ \
		 -lmlx \
		 -framework OpenGL \
		 -framework AppKit \

all: $(NAME)

$(NAME):
	make -C ./libft
	cc $(FLAG1) $(SRC) $(FLAG2) -o $(NAME)

clean:
	make fclean -C ./libft
	rm -rf $(NAME).dSYM

fclean: clean
	rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

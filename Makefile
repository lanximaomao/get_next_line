# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:40:18 by lsun              #+#    #+#              #
#    Updated: 2022/11/15 16:46:10 by lsun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(OBJS)
$(OBJS):
	cc $(CFLAGS) $(BONUS_SRCS)

clean:
	rm -f $(OBJS);

fclean: clean
	rm -f $(OBJS);

re: fclean all

.PHONY: all bonus clean fclean re

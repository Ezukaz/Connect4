# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakaha <katakaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 19:21:57 by katakaha          #+#    #+#              #
#    Updated: 2025/10/29 19:18:28 by katakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix ft_, $(addsuffix .c, \
atoi \
bzero \
calloc \
isalnum \
isalpha \
isascii \
isdigit \
isprint \
memchr \
memcmp \
memcpy \
memmove \
memset \
strchr \
strdup \
strlcat \
strlcpy \
strlen \
strncmp \
strnstr \
strrchr \
tolower \
toupper \
substr \
strjoin \
strtrim \
split \
itoa \
strmapi \
striteri \
putchar_fd \
putnbr_fd \
putstr_fd \
putendl_fd \
lstnew \
lstadd_front \
lstsize \
lstlast \
lstadd_back \
lstdelone \
lstclear \
lstiter \
lstmap))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

# ----------- OBJECTS -------------
%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# ---------- DEPENDENCIES ----------
DEP = $(OBJ:.o=.d)

-include $(DEP)

# ---------- CLEAN RULES -----------
clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

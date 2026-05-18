NAME		= connect4
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
IFLAGS		= -I $(INCDIR)

SRCDIR		= src
OBJDIR		= obj
INCDIR		= inc

LIBFTDIR	= Libft
LIBFT		= $(LIBFTDIR)/libft.a

SRC			= $(addsuffix .c, \
				board \
				return_user_input \
				utils \
				game \
				ai \
				main)

OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP			= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lncurses -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

-include $(DEP)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re

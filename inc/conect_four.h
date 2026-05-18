#ifndef CONECT_FOUR_H
# define CONECT_FOUR_H

#include "libft.h"
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
# define READ_ERROR -1
# define INPUT_ERROR -2
# define SUCCESS 1
#define USER 1
#define COMP 2
#define BLANK 0
#define FALSE 0
#define TRUE 1

typedef struct s_col
{
    int *cells;
    int count;
}       t_col;

typedef struct s_state
{
    t_col   *board;
    int     width;
    int     height;
    int     player;
    int     use_gui;
}           t_state;

typedef struct s_pos
{
    int col;
    int row;
}       t_pos;

t_state *create_board(int width, int height);
void    drop_piece(t_state *state, int col_index, int player);
void    print_board(t_state *state);
int     iswin(t_state *state, int col_index);
int     is_board_full(t_state *state);
void	flush_stdin(void);
int	    return_user_input(void);
void    free_board(t_state *state);
int     is_int_plus(char *buf, int *ans);
int     random_ai(int	width);
int	    stop_user_win_ai(t_state *game);
void	undo_piece(t_state *game, int col);
void    print_board_ncurses(t_state *game);
#endif

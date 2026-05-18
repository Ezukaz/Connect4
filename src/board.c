#include "conect_four.h"

t_state *create_board(int width, int height)
{
    t_state *state = malloc(sizeof(t_state));
    if (!state)
        return (NULL);
    state->width = width;
    state->height = height;

    state->board = malloc(sizeof(t_col) * width);
    if (!state->board)
    {
        free(state);
        return (NULL);
    }

    int i = 0;
    while (i < width)
    {
        state->board[i].cells = malloc(sizeof(int) * height);
        if (!state->board[i].cells)
        {
            free_board(state);
            return (NULL);
        }
        state->board[i].count = 0;
        int j = 0;
        while (j < height)
        {
            state->board[i].cells[j] = 0;
            j++;
        }
        i++;
    }
    return (state);
}

/**
 * @brief Pick column to drop piece into
 *
 * @param state     Current state of the board
 * @param col_index Column index to insert into
 * @param player    Current player
 */
void    drop_piece(t_state *state, int col_index, int player)
{
    if (col_index < 0 || col_index >= state->width)
    {
        ft_putendl_fd("Invalid column index!", 1);
        return ;
    }

    t_col   *current_col = &state->board[col_index];

    if (current_col->count >= state->height)
    {
        ft_putendl_fd("This column is full! Pick a different column.", 1);
        return ;
    }
    current_col->cells[current_col->count] = player;
    current_col->count++;
}

void    print_board(t_state *state)
{
    int x;
    int y;

    y = state->height - 1;
    while (y >= 0)
    {
        x = 0;
        while (x < state->width)
        {
            ft_putstr_fd("| ", 1);
            if (state->board[x].cells[y] == BLANK)
                ft_putchar_fd(' ', 1);
            else if (state->board[x].cells[y] == USER)
                ft_putchar_fd('X', 1);
            else
                ft_putchar_fd('O', 1);
            ft_putchar_fd(' ', 1);
            x++;
        }
        ft_putendl_fd("|", 1);
        y--;
    }
    x = 0;
    while(x < state->width)
    {
        ft_putstr_fd("  ", 1);
        ft_putnbr_fd(x + 1, 1);
        ft_putchar_fd(' ', 1);
        x++;
    }
    ft_putendl_fd("\n", 1);
}

void    print_board_ncurses(t_state *game)
{
    int    x;
    int    y;

    clear();
    y = game->height - 1;
    while (y >= 0)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->board[x].cells[y] == USER)
                mvprintw(game->height - y, x * 2, "X");
            else if (game->board[x].cells[y] == COMP)
                mvprintw(game->height - y, x * 2, "O");
            else
                mvprintw(game->height - y, x * 2, ".");
            x++;
        }
        y--;
    }
    refresh();
}

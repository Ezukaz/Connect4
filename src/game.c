#include "conect_four.h"

/**
 * @brief Count consecutive player pieces in one direction from last played piece
 *
 * @param state Currnet board state
 * @param pos   Last played position
 * @param col_step Direction for x-axis
 * @param row_step Direction for y-axis
 * @return int     Count of consecutive pieces
 */
static int  count_one_way(t_state *state, t_pos pos, int col_step, int row_step)
{
    int count = 0;
    pos.col += col_step;
    pos.row += row_step;
    while (pos.col >= 0 && pos.col < state->width
        && pos.row >= 0 && pos.row < state->height
        && state->board[pos.col].cells[pos.row] == state->player)
    {
        count++;
        pos.col += col_step;
        pos.row += row_step;
    }
    return (count);
}

/**
 * @brief   Added count of consecutive pieces in opposing directions
 *
 * @param state Current board state
 * @param pos   Last played position
 * @param col_step  Direction for x-axis
 * @param row_step  Direction for y-axis
 * @return int      Count of consecutive pieces
 */
static int  check_dir(t_state *state, t_pos pos, int col_step, int row_step)
{
    return (count_one_way(state, pos, col_step, row_step)
        + count_one_way(state, pos, -col_step, -row_step));
}

/**
 * @brief   Check if last play won
 *
 * @param state     Current board state
 * @param col_index Last played column
 * @return int      TRUE or FALSE
 */
int         iswin(t_state *state, int col_index)
{
    const int   dirs[][2] = {{1,0}, {0,1}, {1,1}, {1,-1}};
    t_pos       pos;
    int         i = 0;

    pos.col = col_index;
    pos.row = state->board[col_index].count - 1;
    while (i < 4)
    {
        if (check_dir(state, pos, dirs[i][0], dirs[i][1]) >= 3)
            return (TRUE);
        i++;
    }
    return (FALSE);
}

int  is_board_full(t_state *state)
{
    int i;

    i = 0;
    while (i < state->width)
    {
        if (state->board[i].count < state->height)
            return (FALSE);
        i++;
    }
    return (TRUE);
}

#include <stdlib.h>
#include "libft.h"
#include "conect_four.h"

void    free_board(t_state *state)
{
    if (!state)
        return ;
    int i;
    if (state->board)
    {
        i = 0;
        while (i < state->width)
        {
            if (state->board[i].cells)
            {
                free(state->board[i].cells);
                state->board[i].cells = NULL;
            }
            i++;
        }
        free(state->board);
        state->board = NULL;
    }
    free(state);
}

int is_int_plus(char *buf, int *ans)
{
	int i;
	long lans;

	lans = 0;
	i = 0;
	if (!buf[0])
		return (0);
	while (buf[i])
	{
		if(!ft_isdigit(buf[i]))
			return (0);
		i++;
	}
	i = 0;
	while(buf[i])
	{
		lans = lans * 10 + (buf[i] - '0');
		i++;

	}
	if(lans > INT_MAX)
		return (0);
	*ans = lans;
	return (1);

}

void	undo_piece(t_state *game, int col)
{
	game->board[col].count--;
	game->board[col].cells[game->board[col].count] = BLANK;
}

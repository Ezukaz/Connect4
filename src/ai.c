#include "conect_four.h"
int	random_ai(int	width)
{
	if(width <= 0)
		return 0;
	return	((rand()) % width + 1);
}

int	stop_user_win_ai(t_state *game)
{
	int	i;

	game->player = USER;
	i = 0;
	while (i < game->width)
	{
		if (game->board[i].count < game->height)
		{
			drop_piece(game, i, USER);
			if (iswin(game, i))
			{
				undo_piece(game, i);
				game->player = COMP;
				return (i + 1);
			}
			undo_piece(game, i);
		}
		i++;
	}
	game->player = COMP;
	return (random_ai(game->width));
}

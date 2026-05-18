#include "conect_four.h"

void init_curses()
{
    initscr();
    noecho();
    cbreak();
}

int main(int argc, char **argv)
{
    t_state *game;
    int     width;
    int     height;
    int     input;
    int     col;
    char    buf[12];

    srand(time(NULL));
    if (argc < 3 || argc > 4 ||
        !is_int_plus(argv[1], &width) || !is_int_plus(argv[2], &height) ||
        width < 7 || height < 6
    )
    {
        ft_putendl_fd("Usage: ./connect4 <width> <height> (Min size: 7 6)", 2);
        ft_putendl_fd("Example: ./connect4 7 6", 2);
        return (1);
    }
    game = create_board(width, height);
    if (!game)
    {
        ft_putendl_fd("Error: failed to create board", 2);
        return (1);
    }
    if (argc == 4 && ft_strncmp(argv[3], "--gui", 6) == 0)
        game->use_gui = TRUE;
    else
        game->use_gui = FALSE;
    game->player = rand() % 2 ? USER : COMP;
    if (game->use_gui)
    {
        init_curses();
        print_board_ncurses(game);
    }
    else
    {
        if (game->player == USER)
            print_board(game);
    }
    while (TRUE)
    {
        if (game->player == USER)
        {
            if (game->use_gui)
            {
                mvprintw(game->height + 2, 0, "Player X, enter column: ");
                refresh();
                echo();
                getnstr(buf, 11);
                if (!is_int_plus(buf, &input))
                    input = INPUT_ERROR;
                noecho();
            }
            else
            {
                ft_putendl_fd("Player X, enter column: ", 1);
                input = return_user_input();
            }
        }
        else
        {
            input = stop_user_win_ai(game);
            if (game->use_gui)
            {
                mvprintw(game->height + 2, 0, "Player O played column %d ", input);
                refresh();
            }
            else
            {
                ft_putstr_fd("Player O played column ", 1);
                ft_putnbr_fd(input, 1);
                ft_putstr_fd("\n\n", 1);
            }
        }
        if (input == READ_ERROR)
        {
            ft_putendl_fd("Read error", 2);
            break ;
        }
        if (input == INPUT_ERROR || input < 1 || input > game->width)
        {
            if (game->use_gui)
            {
                mvprintw(game->height + 3, 0, "Invalid input, try again  ");
                refresh();
            }
            else
                ft_putendl_fd("Invalid input, try again", 1);
            continue ;
        }
        col = input - 1;
        if (game->board[col].count >= game->height)
        {
            if (game->use_gui)
            {
                mvprintw(game->height + 3, 0, "Column is full, try again ");
                refresh();
            }
            else
                ft_putendl_fd("Column is full, try again", 1);
            continue ;
        }
        drop_piece(game, col, game->player);
        if (game->use_gui)
            print_board_ncurses(game);
        else
            print_board(game);
        if (iswin(game, col))
        {
            if (game->use_gui)
            {
                mvprintw(game->height + 2, 0, game->player == USER ? "Player X wins!" : "Player O wins!");
                refresh();
                getch();
                endwin();
            }
            else
            {
                if (game->player == USER)
                    ft_putendl_fd("Player X wins!", 1);
                else
                    ft_putendl_fd("Player O wins!", 1);
            }
            break ;
        }
        if (is_board_full(game))
        {
            if (game->use_gui)
            {
                mvprintw(game->height + 2, 0, "Board is full, it's a draw!");
                refresh();
                getch();
                endwin();
            }
            else
                ft_putendl_fd("Board is full, it's a draw!", 1);
            break ;
        }
        if (game->player == USER)
            game->player = COMP;
        else
            game->player = USER;
    }
    free_board(game);
    return (0);
}

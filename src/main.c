#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PLAYER_PAWN 'X'
#define AI_PAWN 'O'
#define EMPTY_CELL '.'

static int parse_positive_int(const char *str, int *value)
{
char *endptr;
long parsed;

if (str == NULL || *str == '\0')
return (0);
parsed = strtol(str, &endptr, 10);
if (*endptr != '\0' || parsed <= 0 || parsed > INT_MAX)
return (0);
*value = (int)parsed;
return (1);
}

static int is_grid_displayable(int rows, int cols)
{
int estimated_width;

estimated_width = 4 * cols + 1;
return (rows <= 40 && estimated_width <= 120);
}

static void print_grid(const char *grid, int rows, int cols)
{
int row;
int col;

if (!is_grid_displayable(rows, cols))
{
printf("Grid is too large to display on a regular terminal (%d x %d).\n", rows,
cols);
return ;
}
printf("\n");
row = 0;
while (row < rows)
{
printf("|");
col = 0;
while (col < cols)
{
printf(" %c |", grid[row * cols + col]);
col++;
}
printf("\n");
row++;
}
printf(" ");
col = 0;
while (col < cols)
{
printf(" %d  ", col + 1);
col++;
}
printf("\n\n");
}

static int column_has_space(const char *grid, int rows, int cols, int col)
{
return (col >= 0 && col < cols && rows > 0 && grid[col] == EMPTY_CELL);
}

static int drop_pawn(char *grid, int rows, int cols, int col, char pawn)
{
int row;

if (col < 0 || col >= cols)
return (-1);
row = rows - 1;
while (row >= 0)
{
if (grid[row * cols + col] == EMPTY_CELL)
{
grid[row * cols + col] = pawn;
return (row);
}
row--;
}
return (-1);
}

static int board_is_full(const char *grid, int rows, int cols)
{
int index;

index = 0;
while (index < rows * cols)
{
if (grid[index] == EMPTY_CELL)
return (0);
index++;
}
return (1);
}

static int count_direction(const char *grid, int rows, int cols,
int row, int col, int row_step, int col_step, char pawn)
{
int count;

count = 0;
row += row_step;
col += col_step;
while (row >= 0 && row < rows && col >= 0 && col < cols
&& grid[row * cols + col] == pawn)
{
count++;
row += row_step;
col += col_step;
}
return (count);
}

static int is_winning_move(const char *grid, int rows, int cols,
int row, int col, char pawn)
{
if (count_direction(grid, rows, cols, row, col, 0, 1, pawn)
+ count_direction(grid, rows, cols, row, col, 0, -1, pawn) >= 3)
return (1);
if (count_direction(grid, rows, cols, row, col, 1, 0, pawn)
+ count_direction(grid, rows, cols, row, col, -1, 0, pawn) >= 3)
return (1);
if (count_direction(grid, rows, cols, row, col, 1, 1, pawn)
+ count_direction(grid, rows, cols, row, col, -1, -1, pawn) >= 3)
return (1);
if (count_direction(grid, rows, cols, row, col, 1, -1, pawn)
+ count_direction(grid, rows, cols, row, col, -1, 1, pawn) >= 3)
return (1);
return (0);
}

static int find_winning_column(char *grid, int rows, int cols, char pawn)
{
int col;
int row;

col = 0;
while (col < cols)
{
if (!column_has_space(grid, rows, cols, col))
{
col++;
continue ;
}
row = drop_pawn(grid, rows, cols, col, pawn);
if (row >= 0 && is_winning_move(grid, rows, cols, row, col, pawn))
{
grid[row * cols + col] = EMPTY_CELL;
return (col);
}
if (row >= 0)
grid[row * cols + col] = EMPTY_CELL;
col++;
}
return (-1);
}

static int choose_ai_column(char *grid, int rows, int cols)
{
int col;
int center;
int tried;

col = find_winning_column(grid, rows, cols, AI_PAWN);
if (col >= 0)
return (col);
col = find_winning_column(grid, rows, cols, PLAYER_PAWN);
if (col >= 0)
return (col);
center = cols / 2;
if (column_has_space(grid, rows, cols, center))
return (center);
if (board_is_full(grid, rows, cols))
return (-1);
col = rand() % cols;
tried = 0;
while (tried < cols && !column_has_space(grid, rows, cols, col))
{
col = (col + 1) % cols;
tried++;
}
if (tried == cols)
return (-1);
return (col);
}

static int read_player_column(const char *grid, int rows, int cols)
{
char buffer[128];
char *endptr;
long parsed;
int column;

while (1)
{
printf("Your move (1-%d): ", cols);
if (fgets(buffer, sizeof(buffer), stdin) == NULL)
{
printf("\nInput ended. Exiting game.\n");
exit(EXIT_SUCCESS);
}
parsed = strtol(buffer, &endptr, 10);
while (*endptr == ' ' || *endptr == '\t')
endptr++;
if (*endptr != '\n' && *endptr != '\0')
{
printf("Invalid input. Please enter a number between 1 and %d.\n", cols);
continue ;
}
if (parsed < 1 || parsed > cols)
{
printf("Invalid column. Please enter a number between 1 and %d.\n", cols);
continue ;
}
column = (int)parsed - 1;
if (!column_has_space(grid, rows, cols, column))
{
printf("Column %d is full. Try another one.\n", column + 1);
continue ;
}
return (column);
}
}

static void play_game(int rows, int cols)
{
char *grid;
size_t grid_size;
int player_turn;
int col;
int row;

if ((size_t)rows > SIZE_MAX / (size_t)cols)
{
fprintf(stderr, "Error: grid size is too large.\n");
exit(EXIT_FAILURE);
}
grid_size = (size_t)rows * (size_t)cols;
grid = malloc(grid_size);
if (grid == NULL)
{
fprintf(stderr, "Error: memory allocation failed.\n");
exit(EXIT_FAILURE);
}
memset(grid, EMPTY_CELL, grid_size);
player_turn = rand() % 2;
printf("%s starts first.\n", player_turn ? "Player" : "AI");
print_grid(grid, rows, cols);
while (1)
{
if (player_turn)
{
col = read_player_column(grid, rows, cols);
row = drop_pawn(grid, rows, cols, col, PLAYER_PAWN);
printf("Player plays column %d.\n", col + 1);
print_grid(grid, rows, cols);
if (is_winning_move(grid, rows, cols, row, col, PLAYER_PAWN))
{
printf("Player wins!\n");
break ;
}
}
else
{
col = choose_ai_column(grid, rows, cols);
if (col < 0)
{
printf("Draw!\n");
break ;
}
row = drop_pawn(grid, rows, cols, col, AI_PAWN);
printf("AI plays column %d.\n", col + 1);
print_grid(grid, rows, cols);
if (is_winning_move(grid, rows, cols, row, col, AI_PAWN))
{
printf("AI wins!\n");
break ;
}
}
if (board_is_full(grid, rows, cols))
{
printf("Draw!\n");
break ;
}
player_turn = !player_turn;
}
free(grid);
}

int main(int argc, char **argv)
{
int rows;
int cols;

srand((unsigned int)time(NULL));
if (argc != 3)
{
fprintf(stderr, "Usage: %s <rows> <cols>\n", argv[0]);
return (EXIT_FAILURE);
}
if (!parse_positive_int(argv[1], &rows)
|| !parse_positive_int(argv[2], &cols)
|| rows < 6 || cols < 7)
{
fprintf(stderr, "Error: invalid grid size. Minimum size is 6 rows and 7 columns.\n");
return (EXIT_FAILURE);
}
play_game(rows, cols);
return (EXIT_SUCCESS);
}

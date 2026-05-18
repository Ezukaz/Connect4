#include "conect_four.h"

static int	input_error(char *buf, int ret, int *ans)
{
	if (ret <= 0)
		return (INPUT_ERROR);
	if (buf[ret - 1] == '\n')
		buf[ret - 1] = '\0';
	else
		buf[ret] = '\0';
	if (!is_int_plus(buf, ans))
		return (INPUT_ERROR);
	return (SUCCESS);
}

void	flush_stdin(void)
{
	int ret;
	char tmp;

	ret = 1;
	while(ret > 0)
	{
		ret = read(0, &tmp, 1);
		if(ret < 0 || tmp == '\n')
			break;
	}
}

int	return_user_input(void)
{
	char	buf[12];
	int		ret;
	int		ans;

	ret = read(0, buf, 11);
	if (ret < 0)
		return (READ_ERROR);
	if (ret == 11 && buf[10] != '\n')
	{
		flush_stdin();
		return (INPUT_ERROR);
	}
	if (input_error(buf, ret, &ans) < 0)
		return (INPUT_ERROR);
	return (ans);
}

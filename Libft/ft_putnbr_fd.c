/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:03 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:03 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			n_to_str[12];
	int				i;
	unsigned int	un;

	i = 11;
	n_to_str[i--] = '\0';
	if (n < 0)
		un = -n;
	else
		un = n;
	while (un > 0)
	{
		n_to_str[i--] = un % 10 + '0';
		un /= 10;
	}
	if (n == 0)
		n_to_str[i--] = '0';
	if (n < 0)
		n_to_str[i--] = '-';
	write(fd, n_to_str + i + 1, 11 - i - 1);
}

// #ifdef TEST
// #include <limits.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int	tests[] = {
// 		INT_MAX,
// 		INT_MIN,
// 		INT_MIN + 1,
// 		INT_MAX -1,
// 		0,
// 		'a',
// 		// INT_MAX + 1, INT_MIN -1,		
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		ft_putnbr_fd(tests[i], 1);
// 		write(1, "\n", 1);
// 	}
// 	return (0);
// }
// #endif

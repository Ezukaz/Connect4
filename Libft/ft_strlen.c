/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:57 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:57 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*tests[] = {
// 		"hello",
// 		"  hi there! ",
// 		"abc\0def",
// 	};
// 	char s[10000];
// 	memset(s, 'a', 9999);
// 	s[9999] = '\0';
// 	char g[3] = {'a', 'b', 'c'};

// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		printf("Test %zu \n	mine: %zu\n	real: %zu\n",
// 			i + 1, ft_strlen(tests[i]), strlen(tests[i]));
// 	}
// 	printf("Test %d \n	mine: %zu\n	real: %zu\n", 5, ft_strlen(s), strlen(s));
// 	printf("Test %d \n	mine: %zu\n	real: %zu\n", 6, ft_strlen(g), strlen(g));
// 	return (0);
// }
// #endif

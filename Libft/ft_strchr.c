/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:22 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:22 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct
// {
// 	const char	*str;
// 	int			chr;
// } t_case;

// int	main(void)
// {
// 	t_case tests[] = {
// 		{"First char", 'F'},
// 		{"Last char", 'r'},
// 		{"Not found", 'z'},
// 		{"Null search", '\0'},
// 		{"", 'j'},
// 		{"", '\0'},
// 		{"Multiple hits", 'i'},
// 		{"Special\nchars", '\n'},
// 		{"teste", 1024},
// 	};
// 	for (unsigned int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		printf("Test %d | %s\n", i + 1, ft_strchr(tests[i].str, tests[i].chr));
// 		printf("Test %d | %s\n", i + 1, strchr(tests[i].str, tests[i].chr));
// 	}
// 	return (0);
// }
// #endif

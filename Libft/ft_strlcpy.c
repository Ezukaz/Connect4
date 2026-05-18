/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:51 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:51 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// #ifdef TEST
// #include <stdio.h>
// #include <bsd/string.h>

// typedef struct
// {
// 	char		dst[20];
// 	char		dst2[20];
// 	const char	*src;
// 	size_t		size;
// } t_case;

// int	main(void)
// {
// 	size_t	mine_cpy;
// 	size_t	real_cpy;

// 	t_case tests[] = {
// 		{"Hi ", "Hi ", "there", 20},
// 		{"Hi ", "Hi ", "yo", 6},
// 		{"1234 ", "1234 ", "56789", 7},
// 		{"abcdef ", "abcdef ", "XYZ", 4},
// 		{"abc ", "abc ", "def", 0},
// 		{"", "", "hello", 10},
// 		{"abc", "abc", "", 10},
// 		{"abc", "abc", "XYZ", 4},
// 		{"a", "a", "b", 1},
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[i]); i++)
// 	{
// 		mine_cpy = ft_strlcpy(tests[i].dst, tests[i].src, tests[i].size);
// 		real_cpy = strlcpy(tests[i].dst2, tests[i].src, tests[i].size);
// 		printf("Test %zu_result&len \n	Mine: %s | %zu \n",
// 			i + 1, tests[i].dst, mine_cpy);
// 		printf("	Real: %s | %zu \n", tests[i].dst2, real_cpy);
// 	}
// 	return (0);	
// }
// #endif

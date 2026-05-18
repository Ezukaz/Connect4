/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:44 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:44 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (size <= dstlen)
		return (size + srclen);
	while (i < size - 1 && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dstlen + srclen);
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
// 	size_t	mine_cat;
// 	size_t	real_cat;

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
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		mine_cat = ft_strlcat(tests[i].dst, tests[i].src, tests[i].size);
// 		real_cat = strlcat(tests[i].dst2, tests[i].src, tests[i].size);
// 		printf("Test %zu_result&len \n	Mine: %s | %zu \n",
// 			i + 1, tests[i].dst, mine_cat);
// 		printf("	Real: %s | %zu \n", tests[i].dst2, real_cat);
// 	}
// 	return (0);	
// }
// #endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:20:10 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:20:10 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*conv_s1;
	unsigned char	*conv_s2;
	size_t			i;

	i = 0;
	conv_s1 = (unsigned char *)s1;
	conv_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (conv_s1[i] != conv_s2[i])
			return (conv_s1[i] - conv_s2[i]);
		i++;
	}
	return (0);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	typedef struct {
// 		const char	*str1;
// 		const char	*str2;
// 		size_t	n;
// 	} t_case;

// 	t_case tests[] = {
// 		{"abc", "abc", 3},
// 		{"abc", "adc", 3},
// 		{"abc", "abd", 3},
// 		{"abc", "adc", 1},
// 		{"abc", "abc", 0},
// 		{"abc", "abcd", 4},
// 		{"ab\0c", "ab\0d", 4},
// 		{"1234", "abcd", 4},
// 		{"aaaaaab", "aaaaaac", 7},
// 	};
// 	for (unsigned int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		printf("Test %d | %s | %s | cmp_limit: %zu\n",
// 			i + 1, tests[i].str1, tests[i].str2, tests[i].n);
// 		printf("	ft_memcmp: %d\n",
// 			ft_memcmp(tests[i].str1, tests[i].str2, tests[i].n));
// 		printf("	   memcmp: %d\n",
// 			memcmp(tests[i].str1, tests[i].str2, tests[i].n));
// 	}
// 	return (0);
// }
// #endif

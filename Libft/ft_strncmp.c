/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:06 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:06 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int	main(void)
// {
// 	const char *tests[][2] = {
// 		{"abc", "abc"},
// 		{"abc", "abd"},
// 		{"ab", "abc"},
// 		{"abc", "ab"},
// 		{"abc", "abcX"},
// 		{"abcX", "abcY"},
// 		{"", ""},
// 		{"", "abc"},
// 		{"abc", ""},
// 		{"abc", "xyz"},
// 		{"abc", "ABC"},
// 		{"\200", "\0"},
// 		{"abc", "abc\0xyz"},
// 		{"abcdef", "abcxyz"},
// 		{"x", "a"},
// 	};

// 	printf(" TstNbr | Mine | Real |  Check  |\n");
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		int	mine_cmp = strncmp(tests[i][0], tests[i][1], i);
// 		int	real_cmp = ft_strncmp(tests[i][0], tests[i][1], i);
// 		if ((mine_cmp < 0 && real_cmp < 0)
// 			|| (mine_cmp == 0 && real_cmp == 0)
// 			|| (mine_cmp > 0 && real_cmp > 0))
// 			printf("  %-3zu   | %4d | %4d | Passed! |\n",
//				i + 1, mine_cmp, real_cmp);
// 		else
// 			printf("  %-3zu   | %4d | %4d | Failed..|\n",
//				i + 1, mine_cmp, real_cmp);
// 	}
// 	return (0);
// }
// #endif

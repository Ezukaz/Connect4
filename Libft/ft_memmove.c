/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:23:18 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:23:18 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// typedef struct
// {
// 	char	str1[50];
// 	char	str2[50];
// 	size_t	n;
// } t_case;

// int	main(void)
// {
// 	t_case tests[] = {
// 		{"What will happen?", "What will happen?", 20},
// 		{"What will happen?", "What will happen?", 20},
// 		{"What will happen?", "What will happen?", 2},
// 		{"What will happen?", "What will happen?", 0},
// 		{"What will happen?", "What will happen?", 20},
// 		{"What will happen?", "you do?", 20},
// 	};
// 	ft_memmove(tests[0].str1, tests[0].str1 + 2, tests[0].n);
// 	printf("Test 1 | %s\n", tests[0].str1);
// 	memmove(tests[0].str2, tests[0].str2 + 2, tests[0].n);
// 	printf("Test 1 | %s\n", tests[0].str1);
// 	ft_memmove(tests[1].str1 + 2, tests[1].str1, tests[1].n);
// 	printf("Test 2 | %s\n", tests[1].str1);
// 	memmove(tests[1].str2 + 2, tests[1].str2, tests[1].n);
// 	printf("Test 2 | %s\n", tests[1].str1);
// 	ft_memmove(tests[2].str1, tests[2].str1 + 2, tests[2].n);
// 	printf("Test 3 | %s\n", tests[2].str1);
// 	memmove(tests[2].str2, tests[2].str2 + 2, tests[2].n);
// 	printf("Test 3 | %s\n", tests[2].str1);
// 	ft_memmove(tests[3].str1 + 2, tests[3].str1, tests[3].n);
// 	printf("Test 4 | %s\n", tests[3].str1);
// 	memmove(tests[3].str2 + 2, tests[3].str2, tests[3].n);
// 	printf("Test 4 | %s\n", tests[3].str1);
// 	ft_memmove(tests[4].str1, tests[4].str1, tests[4].n);
// 	printf("Test 5 | %s\n", tests[4].str1);
// 	memmove(tests[4].str2, tests[4].str2, tests[4].n);
// 	printf("Test 5 | %s\n", tests[4].str1);
// 	ft_memmove(tests[5].str1, tests[5].str2, tests[5].n);
// 	printf("Test 6 | %s\n", tests[5].str1);
// 	memmove(tests[5].str1, tests[5].str2, tests[5].n);
// 	printf("Test 6 | %s\n", tests[5].str1);
// 	return (0);
// }
// #endif

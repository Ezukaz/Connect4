/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:12 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:12 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)hay);
	while (*hay != '\0' && len - i >= needle_len)
	{
		j = 0;
		while (needle[j] != '\0')
		{
			if (hay[j] != needle[j])
				break ;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)hay);
		hay++;
		i++;
	}
	return (NULL);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stdlib.h>
// #include <bsd/string.h>

// typedef struct
// {
// 	const char	*hay;
// 	const char	*needle;
// 	size_t		len;
// } t_case;

// int	main(void)
// {
// 	t_case	tests[] = {
// 		{"Hello world", "world", 11},
// 		{"Hello world", "world", 5},
// 		{"Hello world", "world", 10},
// 		{"Hello", "", 5},
// 		{"", "", 5},
// 		{"", "abc", 5},
// 		{"Hello", "H", 0},
// 		{"abc", "abc", 3},
// 		{"abc", "abcd", 4},
// 		{"ababab", "ab", 6},
// 		{"abcabcabc", "abc", 5},
// 		{"foo bar", "bar", 6},
// 		{"ab\0cd", "b", 4},
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		char	*mine_search =
// 			ft_strnstr(tests[i].hay, tests[i].needle, tests[i].len);
// 		char	*real_search =
// 			strnstr(tests[i].hay, tests[i].needle, tests[i].len);
// 		printf("Test %zu\n	Mine: %s\n	Real: %s\n",
// 			i + 1, mine_search, real_search);
// 	}
// 	return (0);
// }
// #endif

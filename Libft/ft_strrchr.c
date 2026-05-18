/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:20 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:20 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			s += i;
			i = 0;
			flag = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	if (flag)
		return ((char *)s);
	return (NULL);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stdlib.h>
// #include <bsd/string.h>

// typedef struct
// {
// 	const char	*hay;
// 	char	needle;
// } t_case;

// int	main(void)
// {
// 	t_case	tests[] = {
// 		{"abcabc", 'a'},
// 		{"abc", 'z'},
// 		{"abc", '\0'},
// 		{"", '\0'},
// 		{"", 'x'},
// 		{"\200abc", '\200'},
// 		{"Hello", 'H'},
// 		{"abc", 'c'},
// 		{"aaaa", 'a'},
// 		{}
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		char	*mine_search = ft_strrchr(tests[i].hay, tests[i].needle);
// 		char	*real_search = strrchr(tests[i].hay, tests[i].needle);
// 		printf("Test %zu\n	Mine: %s\n	Real: %s\n",
// 			i + 1, mine_search, real_search);
// 	}
// 	return (0);
// }
// #endif

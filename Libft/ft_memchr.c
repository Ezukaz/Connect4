/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:19:38 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:19:38 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cmp_s;

	i = 0;
	cmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (cmp_s[i] == (unsigned char)c)
			return (cmp_s + i);
		i++;
	}
	return (NULL);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stddef.h>
// #include <string.h>

// int	main(void)
// {
// 	char	buf[] = "Hello\0World";
// 	int		tests[][2] = {
// 		{'H', 11},
// 		{'e', 11},
// 		{'o', 11},
// 		{'\0', 11},
// 		{'W', 11},
// 		{'x', 11},
// 		{'l', 3},
// 	};
// 	int	num_tests = sizeof(tests) / sizeof(tests[0]);

// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		int		c = tests[i][0];
// 		size_t	n = tests[i][1];
// 		void	*ft_res = ft_memchr(buf, c, n);
// 		void	*lib_res = memchr(buf, c, n);
//	
// 		printf("Test: %d | char: %c(%03d) | search-limit: %-2zu char(s) \n",
// 			i + 1, (c >= 32 && c <= 127) ? c : 404, c, n);
// 		printf("	ft_memchr: %p\n", ft_res);
// 		printf("	   memchr: %p\n", lib_res);
// 		if (ft_res == lib_res)
// 			printf("	SAME ADDRESS\n");
// 		else
// 			printf("	DIFF ADDRESS\n");
// 	}
// 	return (0);
// }
// #endif

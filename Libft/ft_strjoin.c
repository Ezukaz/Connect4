/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:38 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:38 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*s1_s2;
	size_t	i;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	s1_s2 = malloc((total_len + 1) * sizeof(char));
	if (!s1_s2)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		if (i < ft_strlen(s1))
			s1_s2[i] = s1[i];
		else
			s1_s2[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	s1_s2[i] = '\0';
	return (s1_s2);
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	char	*tests[][2] = {
// 		{"Hello", "World"},
// 		{"42", "Tokyo"},
// 		{"", "World"},
// 		{"Hello", ""},
// 		{"", ""},
// 		{"Hello ", "World\n"},
// 		{"Line1\n", "Line2"},
// 		{"He\0llo", "World"},
// 		{"1234567890", "abcdefghij"},
// 	};
// 	char	*temp;
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		temp = ft_strjoin(tests[i][0], tests[i][1]);
// 		printf("Test %2zu | %s\n", i + 1, temp);
// 	}
// 	free(temp);
// 	temp = NULL;
// 	return (0);
// }
// #endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:32 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:32 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a substring from a string.
 *
 * @param s     Source string.
 * @param start Starting index (0-based).
 * @param len   Maximum number of characters to copy.
 *
 * @return Newly allocated substring, or NULL on allocation failure.
 *
 * @note If start >= strlen(s), an empty string is returned.
 * @note If len exceeds the remaining characters, it will be truncated.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// #ifdef TEST
// #include <stdio.h>
// #include "libft.h"

// typedef struct
// {
// 	char			*str;
// 	unsigned int	start;
// 	size_t			len;
// } t_case;

// int	main(void)
// {
// 	t_case	tests[] = {
// 		{"Divide and conquer!", 0, 5},
// 		{"", 0, 5},
// 		{"Divide and conquer!", 18, 1},
// 		{"Divide and conquer!", 19, 5},
// 		{"Divide and conquer!", 25, 0},
// 		{"Divide and conquer!", 0, 0},
// 		{"Divide and conquer!", 0, -1},
// 		{"Divide and conquer!", 0, 4523},
// 		{"Divide and conquer!", 0, 19},
// 		{"Divide and conquer!", 0, 20},
// 	};
// 	char	*temp;
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		temp = ft_substr(tests[i].str, tests[i].start, tests[i].len);
// 		printf("Test %2zu | %s\n", i + 1, temp);
// 	}
// 	free(temp);
// 	temp = NULL;
// 	return (0);
// }
// #endif

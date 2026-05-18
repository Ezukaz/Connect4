/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:25 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:25 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*my_dup(const char *str, size_t end)
{
	size_t	i;
	char	*dup;

	if (!str)
		return (NULL);
	i = 0;
	dup = malloc((end + 2) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i <= end)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*empty_str;

	if (!s1 || !set)
		return (NULL);
	while (*set && *s1 && isset(set, *s1))
		s1++;
	if (!s1[0])
	{
		empty_str = malloc(1 * sizeof(char));
		if (!empty_str)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	i = 0;
	while (s1[i])
		i++;
	if (i)
		--i;
	while (i >= 0 && isset(set, s1[i]))
		i--;
	if (i < 0)
		return (ft_strdup(""));
	return (my_dup(s1, i));
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	char	*tests[][2] = {
// 		{",,,Hello, World..,.", ",He"},
// 		{",,,Hello, World..,.", ",. "},
// 		{",,,Hello, World..,.", " "},
// 		{"", "Wor"},
// 		{",,,Hello, World..,.", ""},
// 		{",,\t\n,,,Hello, World..,.\n\t,,", ",\n\t"},
// 		{",,\n\t,,,Hello, World..,.", ",\n\t"},
// 		{",,,Hello, World..,.\r\f,,", ",\r\t"},
// 		{",,,Hello, World..,.", "H"},
// 		{",,,Hello, World..,.", ","},
// 		{",,,Hello, World..,.", "98fueui8weio23jt4"},
// 	};
// 	char	*trimmed;
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		trimmed = ft_strtrim(tests[i][0], tests[i][1]);
// 		printf("Test %2zu | %s\n", i + 1, trimmed);
// 		free(trimmed);
// 	}
// 	trimmed = NULL;
// 	return (0);
// }
// #endif

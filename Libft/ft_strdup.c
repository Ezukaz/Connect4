/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:28 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:28 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (len + 1 < len)
		return (NULL);
	i = 0;
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*my_dup;
// 	char	*or_dup;

// 	char	*tests[] = {
// 		"\0",
// 		"",
// 		"Gotta get thru this ",
// 		NULL,
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		my_dup = ft_strdup(tests[i]);
// 		or_dup = strdup(tests[i]);

// 		printf("ft: %s\n", my_dup);
// 		printf("ft: %s\n", or_dup);
// 	}
// 	free(my_dup);
// 	my_dup = NULL;
// 	free(or_dup);
// 	or_dup = NULL;
// 	return (0);
// }
// #endif

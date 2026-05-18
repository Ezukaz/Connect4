/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:40 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:40 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

// #ifdef TEST
// #include <ctype.h>

// int	main(void)
// {
// 	char	tests[] = {
// 		'A',
// 		'Z',
// 		'a',
// 		'z',
// 		128,
// 		200,
// 		EOF,
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		printf("Test %zu\n	Mine:%d\n	Real:%d\n",
// 			i + 1, ft_tolower(tests[i]), tolower(tests[i]));
// 	}
// 	return (0);
// }
// #endif

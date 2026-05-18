/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:25:48 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:25:48 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
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
// 		157,
// 		255,
// 		EOF,
// 	};
// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		printf("Test %zu\n	Mine:%d\n	Real:%d\n",
// 			i + 1, ft_toupper(tests[i]), toupper(tests[i]));
// 	}
// 	return (0);
// }
// #endif

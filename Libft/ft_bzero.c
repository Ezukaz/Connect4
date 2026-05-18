/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:16:20 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:16:20 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*conv;

	conv = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		conv[i] = 0;
		i++;
	}
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <strings.h>

// int	main(void)
// {
// 	char	buf1[20];
// 	char	buf2[20];
// 	size_t	sizes[] = {0, 1, 5, 10, 20};
// 	int		fail;

// 	for (int	i = 0; i < 5; i++)
// 	{
// 		memset(buf1, 0x41, sizeof(buf1));
// 		memset(buf2, 0x41, sizeof(buf2));
// 		bzero(buf1, sizes[i]);
// 		ft_bzero(buf2, sizes[i]);
// 		fail = memcmp(buf1, buf2, sizeof(buf1));
// 		printf("Test %d | size = %2zu | %s\n",
//			i + 1, sizes[i], (fail ? "NG" : "They are the same!"));
// 	}
// 	return (0);
// }
// #endif

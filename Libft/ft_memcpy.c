/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:24:12 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/24 20:31:22 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*new_dest;
	const unsigned char	*new_src;

	new_dest = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	while (n--)
		*new_dest++ = *new_src++;
	return (dest);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src1[] = "Hello World";
// 	char	dest1[20];
// d	char	dest2[20];
// d	char	src2[] = "";
// d	
// 	memcpy(dest1, src1, 5);
// 	ft_memcpy(dest2, src1, 5);
// 	printf("1: %s | %s\n", dest1, dest2);

// 	memcpy(dest1, src1, strlen(src1) + 1);
// 	ft_memcpy(dest2, src1, strlen(src1) + 1);
// 	printf("2: %s | %s\n", dest1, dest2);

// 	memcpy(dest1, src1, 0);
// 	ft_memcpy(dest2, src1, 0);
// 	printf("3: %s | %s\n", dest1, dest2);

// 	memcpy(dest1, src2, 1);
// 	ft_memcpy(dest2, src2, 1);
// 	printf("4: %s | %s\n", dest1, dest2);

// 	char	overlap1[] = "abcdefgh";
// 	char	overlap2[] = "abcdefgh";
// 	memcpy(overlap1 + 2, overlap1, 5);
// 	ft_memcpy(overlap2 + 2, overlap2, 5);
// 	printf("5: %s | %s\n", overlap1, overlap2);

// 	return (0);
// }
// #endif

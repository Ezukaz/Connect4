/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:16:46 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:16:46 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			total;

	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	unsigned char	*ptr;
// 	size_t	test_cases[][2] = {
// 		{1, 1},
// 		{5, 4},
// 		{0, 5},
// 		{5, 0},
// 		{0, 0},
// 		{65536, 316215},
// 	};

// 	for (size_t i = 0; i < (sizeof(test_cases) / sizeof(test_cases[0])); i++)
// 	{
// 		size_t nmemb = test_cases[i][0];
// 		size_t size = test_cases[i][1];

// 		ptr = ft_calloc(nmemb, size);
// 		printf("Test %zu | nmemb=%-10zu , size=%-10zu | ptr=%-20p | ",
// 			i + 1, nmemb, size, ptr);
// 		if (!ptr)
// 			printf("Allocation failed or zero-size\n");
// 		else
// 		{
// 			size_t total = nmemb * size;
// 			size_t j;
// 			for (j = 0; j < total; j++)
// 				if (ptr[j] != 0)
// 					break;
// 			if (j == total)
// 				printf("All bytes zero\n");
// 			else
// 				printf("Memory not zero\n");
// 		}
// 		free(ptr);
// 		ptr = NULL;
// 	}
// 	return (0);
// }
// #endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:23:43 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:23:43 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
		new_s[i++] = (unsigned char)c;
	return (s);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	buf[50];
// 	char	buf2[50];
// 	int		n;
// 	int		i;

// 	n = 50;
// // TEST 1
// 	ft_memset(buf, '7', 50);
// 	memset(buf2, '7', 50);
// 	i = 0;
// 	printf("Test 1 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// 	i = 0;
// 	printf("Test 1 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// // TEST 2
// 	ft_memset(buf, 'Z', 5);
// 	memset(buf2, 'Z', 5);
// 	i = 0;
// 	printf("Test 2 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// 	i = 0;
// 	printf("Test 2 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// // TEST 3
// 	ft_memset(buf, 'j', 0);
// 	memset(buf2, 'j', (size_t)0);
// 	i = 0;
// 	printf("Test 3 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// 	i = 0;
// 	printf("Test 3 | ");
// 	while (i < n)
// 		printf("%c", buf[i++]);
// 	printf("\n");
// // TEST 4
// 	ft_memset(buf, 0, 50);
// 	memset(buf2, 0, 50);
// 	i = 0;
// 	printf("Test 4 | ");
// 	while (i < n)
// 		printf("%2x", buf[i++]);
// 	printf("\n");
// 	i = 0;
// 	printf("Test 4 | ");
// 	while (i < n)
// 		printf("%2x", buf[i++]);
// 	printf("\n");
// // TEST 5
// 	ft_memset(buf, 255, 50);
// 	memset(buf2, 255, 50);
// 	i = 0;
// 	printf("Test 5 | ");
// 	while (i < n)
// 		printf("%2x", buf[i++]);
// 	printf("\n");
// 	i = 0;
// 	printf("Test 5 | ");
// 	while (i < n)
// 		printf("%2x", buf[i++]);
// 	printf("\n");
// // TEST 6
// 	char buf3[1000];
// 	ft_memset(buf3, 42, 1000);
// 	i = 0;
// 	printf("Test 6 | ");
// 	while (i < n)
// 		printf("%2x", buf3[i++]);
// 	printf("\n");
// 	char buf4[1000];
// 	memset(buf4, 42, 1000);
// 	i = 0;
// 	printf("Test 6 | ");
// 	while (i < n)
// 		printf("%2x", buf4[i++]);
// 	printf("\n");
// // TEST 7
// 	int arr[5];
// 	ft_memset(arr, 76, sizeof(arr));
// 	i = 0;
// 	printf("Test 7 | ");
// 	while (i < n)
// 		printf("%2x", arr[i++]);
// 	printf("\n");
// 	int arr2[5];
// 	memset(arr2, 76, sizeof(arr2));
// 	i = 0;
// 	printf("Test 7 | ");
// 	while (i < n)
// 		printf("%2x", arr2[i++]);
// 	printf("\n");

// 	return (0);
// }
// #endif

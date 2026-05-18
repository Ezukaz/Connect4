/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:18:10 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:18:10 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	int_converter(char *dst, int index, int nbr)
{
	long	temp;

	temp = nbr;
	if (nbr < 0)
		temp *= -1;
	while (index)
	{
		dst[index] = temp % 10 + '0';
		temp /= 10;
		index--;
	}
	dst[index] = temp + '0';
	return ;
}

static int	digit_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = digit_count(n);
	if (n == 0)
		i = 1;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	int_converter(str, i, n);
	if (n < 0)
		str[0] = '-';
	return (str);
}

// #ifdef TEST
// #include <stdio.h>
// #include <string.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	tests[] = {
// 		INT_MAX,
// 		INT_MIN,
// 		INT_MIN + 1,
// 		INT_MAX -1,
// 		0,
// 		'a',
// 		// INT_MAX + 1, INT_MIN -1,		
// 	};
// 	char	*temp;

// 	for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
// 	{
// 		temp = ft_itoa(tests[i]);
// 		printf("Test %2zu | %s\n", i + 1, temp);
// 	}
// 	free(temp);
// 	temp = NULL;
// 	return (0);
// }
// #endif

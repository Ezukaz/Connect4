/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:16:33 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:16:33 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	int		result;

	i = 0;
	flag = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = 10 * result + (str[i++] - '0');
	return (result * flag);
}

// #ifdef TEST
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*tests[] = {
// 		"0",
// 		"123",
// 		"-123",
// 		"   -123",
// 		"   +123",
// 		"    123",
// 		"   000123",
// 		"   -000123",
// 		"   +000123",
// 		"-999999999",
// 		"999999999",
// 		"  -2147483648",
// 		"   2147483647",
// 		"  -2147483649",
// 		"   2147483648",
// 		"abc",
// 		"   abc",
// 		"   231cd456",
// 		"",
// 		"  ",
// 		NULL,
// 	};	
// 	for (int	i = 0; tests[i]; i++)
// 	{
// 		int	mine = ft_atoi(tests[i]);
// 		int	real = atoi(tests[i]);
// 		printf("Test %-15s | atoi: %-12d | ft_atoi: %-12d | %s\n",
// 			tests[i],
// 			real,
// 			mine,
// 			(real == mine ? "Good" : "NG"));
// 	}
// 	return (0);
// }
// #endif

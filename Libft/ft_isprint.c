/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:18:01 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:18:01 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", (ft_isprint(123) ? "True" : "False"));
// }
// #endif

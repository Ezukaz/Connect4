/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:17:13 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:17:13 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", (ft_isascii(NULL) ? "True" : "False"));
// }
// #endif

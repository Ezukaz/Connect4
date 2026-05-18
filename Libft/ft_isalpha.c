/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:17:04 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:17:04 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", (ft_isalpha(122) ? "True" : "False"));
// }
// #endif

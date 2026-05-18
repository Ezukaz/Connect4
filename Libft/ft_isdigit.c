/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:17:45 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:17:45 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #ifdef TEST
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%s\n", (ft_isdigit(-5) ? "True" : "False"));
// }
// #endif

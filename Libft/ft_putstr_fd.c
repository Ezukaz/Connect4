/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:24:09 by katakaha          #+#    #+#             */
/*   Updated: 2025/10/31 19:24:09 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// #ifdef TEST

// int	main(void)
// {
// 	char	*str = "This is read-only!";

// 	//str = NULL;
// 	ft_putstr_fd(str, 1);
// 	return (0);
// }
// #endif

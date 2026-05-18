/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:12:56 by katakaha          #+#    #+#             */
/*   Updated: 2025/11/02 19:10:42 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_strdup(";lakdsfj");
// 	if (!str)
// 		return (1);
// 	t_list	*test_lst = ft_lstnew(str);
// 	printf("%s", (char *)test_lst->content);
// 	return (0);
// }

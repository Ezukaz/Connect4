/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:10:56 by katakaha          #+#    #+#             */
/*   Updated: 2025/11/05 12:58:19 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*first;

// 	first = ft_lstnew(ft_strdup("first content"));
// 	ft_lstadd_front(&first, ft_lstnew(ft_strdup("next content")));
// 	printf("%s\n", (char *)first -> content);
// 	printf("%s\n", (char *)first -> next);
// 	free(first -> content);
// 	free(first -> next);
// 	free(first);
// 	return (0);
// }

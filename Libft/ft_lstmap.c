/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakaha <katakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:43:35 by katakaha          #+#    #+#             */
/*   Updated: 2025/11/05 17:43:11 by katakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tail;
	t_list	*head;
	t_list	*temp;
	void	*content;

	head = NULL;
	tail = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = temp;
		else
			tail->next = temp;
		tail = temp;
		lst = lst->next;
	}
	return (head);
}

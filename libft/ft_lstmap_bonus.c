/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:39:39 by marvin            #+#    #+#             */
/*   Updated: 2023/11/14 01:39:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*modified;

	if (!del || !f || !lst)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	modified = l;
	while (lst && lst->next)
	{
		if (!modified || !l)
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		modified->next = ft_lstnew(f(lst->next->content));
		modified = modified->next;
		lst = lst->next;
	}
	return (l);
}

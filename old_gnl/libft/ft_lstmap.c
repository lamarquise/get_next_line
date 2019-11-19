/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:33:32 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 17:05:07 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (!f || !lst)
		return (0);
	if (lst)
	{
		if (!(new = f(lst)))
			return (NULL);
		new->next = ft_lstmap(lst->next, f);
	}
	return (new);
}

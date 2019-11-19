/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:14:24 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 15:49:52 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = (void*)malloc(content_size)))
		{
			free(elem);
			return (0);
		}
		elem->content = ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}

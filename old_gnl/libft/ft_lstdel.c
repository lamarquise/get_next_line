/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:54:43 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/18 19:14:18 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	tmp = *alst;
	while (tmp)
	{
		elem = tmp;
		tmp = tmp->next;
		del(elem->content, elem->content_size);
		free(elem);
	}
	*alst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:47:40 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/19 19:19:55 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstgen(char *s, char c)
{
	int		i;
	t_list	*list;
	char	**tab;

	i = 0;
	list = NULL;
	if (!(tab = ft_strsplit(s, c)))
		return (0);
	while (tab[i])
	{
		ft_lstadd(&list, ft_lstnew(tab[i], ft_strlen(tab[i])));
		++i;
	}
	return (list);
}

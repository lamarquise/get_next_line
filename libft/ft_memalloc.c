/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 20:00:47 by erlazo            #+#    #+#             */
/*   Updated: 2019/03/12 21:11:08 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	a;
	char			*ret;

	a = 0;
	if (!(ret = (char*)malloc(sizeof(char) * size)))
		return (0);
	while (a < size)
	{
		ret[a] = '\0';
		++a;
	}
	return ((void*)ret);
}

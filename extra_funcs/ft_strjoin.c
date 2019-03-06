/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 10:41:23 by agaspard          #+#    #+#             */
/*   Updated: 2019/03/06 16:58:11 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
 ** appends s2 to the end of s1, allocates memory and returns the new string
*/

int			ft_strlen(char *str)
{
	int		a;

	a = 0;
	while (str[a])
		++a;
	return (a);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*str1;
	char	*str2;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char*)s1;
	str2 = (char*)s2;
	len = ft_strlen(str1) + ft_strlen(str2);
	if ((dst = (char*)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	while (*str1)
		*(dst++) = *(str1++);
	while (*str2)
		*(dst++) = *(str2++);
	*dst = '\0';
	return (dst - len);
}

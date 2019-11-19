/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:12:36 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/20 22:31:41 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_trim(char *s)
{
	int		len;
	char	*s_bis;

	if (!s)
		return (1);
	len = ft_strlen(s);
	s_bis = s + len - 1;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	while (len-- != 0 && (*s_bis == ' ' || *s_bis == '\t' || *s_bis == '\n')
	&& s_bis > s)
		s_bis--;
	return (s_bis - s + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		len;
	int		idx;

	len = ft_strlen_trim((char*)s);
	idx = 0;
	if (!s)
		return (0);
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	while (idx < len)
		ret[idx++] = *s++;
	return (ret);
}

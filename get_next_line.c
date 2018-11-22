/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erlazo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:56:51 by erlazo            #+#    #+#             */
/*   Updated: 2018/11/22 18:49:21 by erlazo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"



int		gnl(const int fd, char **line, t_gnllst *elem)
{
	char	buff[BUFF_SIZE + 1];
	int		i;


	while (read(fd, &buff, BUFF_SIZE) < 0)
	{
		if (!elem->save = memalloc(sizeof(char) * (BUFF_SIZE + 1)))
			return (-1)
		//may need a while and a counter to fill save...
		elem->save = buff;					//should prolly malloc, may have to call another function and send it the buff_size
		
	}
	//reads the fd file, using the buffer
	//handles the return 1, 0 or -1
	//
}


int		get_next_line(const int fd, char **line)
{
	static t_gnllst		*lst = NULL;			//double pointer ???
	t_gnllst			*current;
	//something
	
	//so somthing that makes sure its using the right element int the list, which if first time running func will be nothing
	//so goes throught the list and finds the right fd
	
	//calls the next func that does the core of the gnl stuff and also at some 
	//frees
	//return

}

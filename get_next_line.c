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


#include <stdio.h>			// delete this line !!!!!!!!!!!!!!!



#include "get_next_line.h"



	// ok so this takes the fd reads the file, allocates to the right places, sets line & elem right, 
	// and returns a failed or not value
	//we have room to add more error conditions, which should come in handy...

void	gnl(const int fd, char **line, t_gnllst **elem)			// leaving it void for now
{															// don't actually need to send fd, it's already there
	char	buff[BUFF_SIZE + 1];
	int		i;


	printf("further test1\n");
	
	(*elem)->len = 0;								//init elsewhere
	i = 0;

	printf("further test2\n");

	while (read(fd, &buff, BUFF_SIZE) > 0)
	{
		printf("further test3\n");
		i = (int)ft_strchr(buff, DELIM) - (int)buff;
		(*elem)->len += i;
		*line = ft_strjoin(*line, ft_strncpy(ft_strnew(i), buff, i));
		// ok so strjoin of an strncpy of an strnew that takes an strchr of the DELIM or \0
	}
		//memalloc here ???
	
	printf("further test4\n");

	if (!((*elem)->save = ft_memalloc(*(*elem)->len)))
		return ;				// -1 i think when we change back from void
	(*elem)->save = *line;
//		free(buff);				// ????
	return ;			// or is it 1 ???
}

int		get_next_line(const int fd, char **line)
{
	static t_gnllst		*lst = NULL;			//double pointer ???
	t_gnllst			*new_elem;
//	t_gnllst			*tmp;

	
//	tmp = NULL;
	
//	printf("inner test1\n");
	

//	if (*lst)
//		tmp = *lst;

//	printf("inner test2\n");

	while (lst)
	{
		if (lst->fd == fd)
		{
			gnl(fd, line, &lst);
			return (1);				// i think it's 1
		}
		lst = lst->next;
	}

//	printf("inner test3\n");
	
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))))
		return (-1);

//	printf("inner test4\n");

	new_elem->fd = fd;
	new_elem->next = NULL;

//	printf("inner test5, elem->fd: %i\n", new_elem->fd);

	if (!lst)
		lst = new_elem;
	else
		lst->next = new_elem;

	printf("inner test6\n");

	gnl(fd, line, &new_elem);
	return (1);

// free aroud here i guess or maybe in the othe func, like if get to \0 then you free the element of the node.
// or have the return of the other func indicate that it has reached the end and then here free the node.
	// yea this needs some work...











/*

	if (lst)
	{
		lst = lst->start;
		while (lst && lst->fd != fd)
			lst = lst->next;
		// we are eighet at the elem that has the right fd or at the end of lst...
		if (lst->fd == fd)
			gnl(fd, line, &lst);		// equals something .... the protection
	}
	if (!lst || lst_fd != fd)
	{
		if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))));
			return (-1);
		lst->next = new_elem;
		new_elem->fd = fd;
		new_elem->start = lst->start;
		new_elem->next = NULL;
		gnl(fd, line, &new_elem);		//some sort of protection
	}


	if (!lst)
	{
		lst = new_elem;
		
	}



	if (!lst)
		lst = new_elem;					// will that work before the malloc ???
	lst->start = lst;
	while (lst)
	{
		if (lst->fd == fd)			// must protect all this shit i think
		{
			gnl(fd, line, &lst);
			break;
		}
		lst = lst->next;
	}
	if (!(new_elem = (t_gnllst*)malloc(sizeof(t_gnllst))));
		return (-1);		// -1 i think
	new_elem->fd = fd;
	new_elem->next = NULL;			//fuck how do i link properly... 
	



	if (!lst)
	{
		lst = new_elem;
		//somehow set start to be the begining.
	}
		
	
*/





	//so somthing that makes sure its using the right element int the list, which if first time running func will be nothing
	//so goes throught the list and finds the right fd
	
	//calls the next func that does the core of the gnl stuff and also at some 
	//frees
	//return

}

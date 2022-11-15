/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/15 17:13:58 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// function to create linked list,
// each node saves content up to the new line character
// after return, free the node

//char	*get_next_line(int fd)
//{
//	char *ret;



//	return (ret);
//}

int	main(void)
{
	int	fd;
	int bufsize;
	char buf[5];

	bufsize = 5;
	//open the file
	fd = open("tests.txt", O_RDWR);
	read(fd, buf, bufsize);
	printf("%d\n", fd);
	printf("%s\n", buf);

	//close the file
	return (0);
}

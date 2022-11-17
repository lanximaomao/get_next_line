/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/17 00:45:39 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*get_next_line(int fd)
//{
//	//read the whole file into a string
//	//line = ft_split("file", ' ');
//	return (NULL);
//}

int	main(void)
{
	int		fd;
	int		bufsize;
	char	buf[2];
	char	*file;
	int		read_ret;
	int		count;
	int		i;
	int		j;
	int		str;

	/*open the file*/
	fd = open("test1.txt", O_RDWR);
	if (fd == -1)
	{
		write(1, "File open fail.\n", 16);
		return (0);
	}
	count = 0;
	bufsize = 2;
	file = NULL;
	while (read(fd, buf, bufsize) == bufsize)
	{

		//printf("%s\n", file);
		//printf("%s\n", buf);
		file = ft_strjoin(file, buf);
		printf("%s\n", file);
		count++;
	}

	// things to be fixed
	// strjoin cannot handel a null;
	// 





	//printf("after %d\n", read_ret);
	//count = count * bufsize + read_ret ;
	//file = (char *)malloc(sizeof(char) * (count + 1));
	//if (!file)
	//	return (1);
	//create a string
	//file[count] = 0;
	//i = 0;

	//if (i < count)
	//{
	//	read_ret = read(fd, buf, bufsize);
	//	//printf("%s\n", buf);
	//	j = 0;
	//	while (j < bufsize)
	//	{
	//		file[i] = buf[j];
	//		i++;
	//		j++;
	//	}
	//	i += read_ret;
	//}
	//i += bufsize;


	//get next line
	//close the file
	return (0);
}

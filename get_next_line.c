/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/17 15:45:12 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*get_next_line(int fd)
//{

//	return (NULL);
//}

size_t	ft_strlen_nl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

int	main(void)
{
	int			fd;
	char		*buf;
	char		*ret;
	int			read_ret;
	int			str;
	static char	*processer;
	int i;


	/* open the file */
	fd = open("test1.txt", O_RDWR);
	if (fd == -1)
	{
		write(1, "File open fail.\n", 16);
		return (0);
	}
	/* save one buffer to a static string */
	processer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!processer)
		return (0);
	i = 0;
	while (read(fd, buf, BUFFER_SIZE))
	{
		//printf("buf is %s\n", buf);
		while (i < BUFFER_SIZE)
		{
			processer[i] = buf[i];
			i++;
		}
		processer[i] = '\0';

		//check if there is new line in the processer

		if (ft_strchr(processer, '\n') && *processer)
		{
			//create the line
			ret = ft_substr(processer, 0, ft_strlen_nl(processer));
			printf("%s", ret);
			return(0);
			//trim it out
			//else just keep on reading
		}
	printf("%c\n", processer[0]);
	return (0);
	}
}





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

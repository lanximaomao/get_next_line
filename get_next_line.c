/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/21 14:48:43 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_trim(char *processer)
{
	char *ret;
	char *temp;
	int	len;

	len = ft_strlen_nl(processer);
	//printf("len to newline is %d\n", len);
	if (len != 0)
	{
		ret = (char*)malloc(sizeof(char)*(len + 1));
		if(!ret)
			return (NULL);
		temp = ft_strchr(processer, '\n') + 1  ; // + 1 to not include the new line
		ft_strlcpy(ret, temp, ft_strlen(temp) + 1);
		free(processer);
	}
	else // reaching the end of the file, no need to trim, just free
		{
			free(processer);
			return (NULL);
		}
	return (ret);
}

char	*ft_out(char *processer) // return the newline and free the newline
{
	int i;
	int j;
	int len;
	char *nl;

	i = 0;
	j = 0;
	while (processer[i])
	{
		if (processer[i] == '\n' || processer[i + 1] == '\0')
		{
			len = i + 1;
			//printf("out len is %d\n", len);
			nl = malloc(sizeof(char) * (len + 1));
			i = 0;
			while (i < len)
			{
				nl[i] = processer[i];
				i++;
			}
			nl[i] = '\0'; //add a null terminator
			return (nl);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			i;
	//char		*buf;
	char	buf[BUFFER_SIZE + 1];
	char *ret;
	static char	*processer;
	int read_bytes;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
		return (NULL);
	read_bytes = 1;
	//buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!processer)
		{
			processer = (char *)malloc(sizeof(char) * 1);
			processer[0] = '\0';
		}
	if (!processer) // remove malloc protection for buff
		return (0);
	i = 0;
	//write(1, "here\n", 5);
	//printf("start processor %s\n", processer);
	//ft_bzero(buf, BUFFER_SIZE + 1);
	if (ft_is_newline(processer) == 0) // if processer has no new line
	{
		while (read_bytes && ft_is_newline(processer) == 0) // as long as there is no new line, read more
		{
			//printf("%lu\n", ft_strlen(buf));
			read_bytes = read(fd, buf, BUFFER_SIZE);
			buf[read_bytes] = '\0';
			//printf("buf is %s\n", buf);
			processer = ft_strjoin(processer, buf); //save to processer. do we need to free buf? typecasting?
			//printf("processer is %s\n", processer);


			if (ft_is_newline(processer) == 1) // if after join, there is now a new line
			{
				//write(1, "here\n", 5);
				ret = ft_out(processer);
				processer = ft_trim(processer);
				//free(buf);
				return(ret);
			}
		}

		//printf("my buf is %s\n", buf);
		if (ft_is_newline(processer) == 0) // what if after all the possible joins, still no new line?
		{
			//write(1, "there\n", 6);
			ret = ft_out(processer);
			processer = ft_trim(processer);
			//printf("after trim processer is %s\n", processer);
			//free(buf);
			return(ret);
		}
		//free(buf);
	}
	else // if processer already have a new line, skip reading just process
	{
		ret = ft_out(processer);
		//printf("before trim: %s\n", processer);
		processer = ft_trim(processer);
		//printf("after trim: %s\n", processer);
		//free(buf);
		return (ret);
		//write(1, "here\n", 5);
	}
	//if (buf == NULL) // if reaches the end of my file
	//	return (NULL);
	return (NULL);
}


//int	main(void)
//{
//	int	fd;
//	int	i;
//	char *str;

//	i = 0;
//	fd = open("42_with_nl", O_RDWR);
//	//printf("%d\n", fd);
//	while (i < 10)
//	{
//		str = get_next_line(fd);
//		printf("my next line is %s\n", str);
//		free(str);
//		i++;
//	}
//	close(fd);
//	return (0);
//}

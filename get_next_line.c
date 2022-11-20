/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/20 14:39:48 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_trim(char *processer)
{
	char *ret;
	char *temp;
	int	len;

	len = ft_strlen_nl(processer);
	printf("len is %d\n", len);
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
		free(processer);
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
		if (processer[i] == '\n')
		{
			len = i + 1;
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
	char		*buf;
	char *ret;
	static char	*processer;

	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	processer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!processer || !buf)
		return (0);
	i = 0;
	if (ft_is_newline(processer) == 0) // if processer has no new line
	{
		while (read(fd, buf, BUFFER_SIZE) && ft_is_newline(processer) == 0) // as long as there is no new line, read more
		{
			processer = ft_strjoin(processer, buf); //save to processer. do we need to free buf? typecasting?
		}
		if (ft_is_newline(processer) == 1) // if there is now a new line
		{
			ret = ft_out(processer);
			printf("before trim: %s\n", processer);
			processer = ft_trim(processer);
			printf("after trim: %s\n", processer);
		}
	}
	else // if processer already have a new line, skip reading just process
	{
		processer = ft_trim(processer);
		return (ft_out(processer));
	}
	if (buf == NULL) // if reaches the end of my file
		return (NULL);
	return (NULL);
}

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test1.txt", O_RDWR);
	while (i < 5)
	{
		printf("%s\n", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}

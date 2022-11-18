/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/19 00:56:44 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_trim(char *processer) // can not test here because the processer is defined as in stack not dynamically allocated by malloc
{
	char *ret;
	int	len;
	len = ft_strlen_nl(processer);
	ret = (char*)malloc(sizeof(char)*(len + 1));
	if(!ret)
		return (NULL);
	ft_strlcpy(ret, processer, len + 1);
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
			processer = ft_strjoin(processer, buf); //save to processer. do we need to free buf? typecasting?
		if (ft_is_newline(processer) == 1) // if there is now a new line
		{
			processer = ft_trim(processer);
			return (ft_out(processer));
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

//int	main(void)
//{
//	int	fd;
//	int	i;

//	i = 0;
//	fd = open("one_byte.txt", O_RDWR);
//	while (i < 5)
//	{
//		printf("%s\n", get_next_line(fd));
//		i++;
//	}
//	close(fd);
//	return (0);
//}

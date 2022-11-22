/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/22 14:50:07 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* am I freeing something that doesn't exist?*/
/* after free, reset to null */

int	ft_is_newline(char *processor)
{
	int	i;

	i = 0;
	while (processor[i])
	{
		if (processor[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_trim(char *stash)
{
	char	*ret;
	char	*temp;
	int		len;

	len = ft_strlen_nl(stash);
	if (len != 0)
	{
		temp = ft_strchr(stash, '\n') + 1;
		ret = ft_strdup(temp);
		free(stash);
		stash = NULL;
	}
	else
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (ret);
}

char	*ft_out(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*nl;

	i = 0;
	j = 0;
	while (stash[i])
	{
		if (stash[i] == '\n' || stash[i + 1] == '\0')
		{
			len = i + 1;
			nl = malloc(sizeof(char) * (len + 1));
			i = 0;
			while (i < len)
			{
				nl[i] = stash[i];
				i++;
			}
			nl[i] = '\0';
			return (nl);
		}
		i++;
	}
	return (NULL);
}

char	*ft_fd_check(int fd, char *stash)
{
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash)
		return (NULL);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*ret;
	static char	*stash;
	int			read_bytes;

	stash = ft_fd_check(fd, stash);
	if (stash == NULL)
		return (NULL);
	read_bytes = 1;
	if (ft_is_newline(stash) == 0)
	{
		while (read_bytes != 0 && ft_is_newline(stash) == 0)
		{
			read_bytes = read(fd, buf, BUFFER_SIZE);
			buf[read_bytes] = '\0';
			stash = ft_strjoin(stash, buf);
			if (ft_is_newline(stash) == 1)
				break ;
		}
	}
	ret = ft_out(stash);
	stash = ft_trim(stash);
	return (ret);
}

//int	main(void)
//{
//	int	fd;
//	int	i;
//	char *str;

//	i = 0;
//	fd = open("multiple_line_no_nl", O_RDWR);
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

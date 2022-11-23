/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/23 20:41:46 by linlinsun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//update
static char	*ft_trim(char *stash)
{
	char	*ret;
	char	*temp;
	int		len;

	len = ft_strlen_nl(stash);
	if (len != 0)
	{
		temp = ft_strchr(stash, '\n') + 1;
		ret = ft_strdup(temp);
	}
	else
		ret = NULL;
	free(stash);
	stash = NULL;
	return (ret);
}

//update
static char	*ft_out(char *stash)
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
			nl = ft_calloc((len + 1), sizeof(char));
			if (!nl)
				return (NULL);
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

static char	*ft_fd_check(int fd, char *stash)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = (char *)ft_calloc(1,1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	//char		buf[BUFFER_SIZE + 1];
	char		*buf;
	char		*ret;
	static char	*stash[1024];
	int			read_bytes;

	stash[fd] = ft_fd_check(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	read_bytes = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	if (ft_strchr(stash[fd], '\n') == 0)
	{
		while (read_bytes != 0 && ft_strchr(buf, '\n') == 0)
		{
			read_bytes = read(fd, buf, BUFFER_SIZE);
			buf[read_bytes] = '\0';
			stash[fd] = ft_strjoin_gnl(stash[fd], buf);
		}
	}
	free(buf);
	ret = ft_out(stash[fd]);
	stash[fd] = ft_trim(stash[fd]);
	return (ret);
}

/*
int	main(int argc, char** argv)
{
	int		i;
	int		fd[10];
	char	*str;

	i = 1;
	while (argv[i])
	{
		fd[i] = open(argv[i], O_RDWR);
		printf("my fd is %d\n", fd[i]);
		str = get_next_line(fd[i]);
		printf("my next line is %s\n", str);
		free(str);
		close(fd[i]);
		i++;
	}
	return (0);
}
*/

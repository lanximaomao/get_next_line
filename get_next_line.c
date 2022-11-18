/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/18 19:58:41 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	if (*s == a)
		return ((char *)s);
	return (0);
}

/* modified for get_next_line */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;
	size_t	i;
	size_t	j;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	joint_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
			+ 1);
	if (!joint_str)
		return (NULL);
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			joint_str[i] = s1[i];
		if (i >= ft_strlen(s1))
			joint_str[i] = s2[j++];
		i++;
	}
	joint_str[i] = '\0';
	return (joint_str);
}

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

char	*ft_trim(char *processer) // strchr --> free --> return strchr
{
	char *ret;
	ret = strchr(processer, '\n');
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
		}
		i++;
	}
	return (nl);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buf;
	char		*out;
	static char	*processer;

	if (fd == -1)
		return (NULL);
	processer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!processer)
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

int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test1.txt", O_RDWR);
	while (i < 10)
	{
		get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

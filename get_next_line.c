/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:35:41 by lsun              #+#    #+#             */
/*   Updated: 2022/11/18 21:19:49 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*new_s;

	i = 0;
	new_s = (char *)s;
	while (i < n)
	{
		new_s[i] = 0;
		i++;
	}
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlen_nl(const char *str) // for a string "abc\ndefg\n\n\n\n123" return 4
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len + 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*src_;

	src_ = (char *)src;
	if (!dstsize)
		return (ft_strlen((const char *)src_));
	if (*src_ == '\0')
		*dst = '\0';
	while (dstsize > 1 && *src_ != '\0')
	{
		*dst = *src_;
		dst++;
		src_++;
		dstsize--;
	}
	*dst = '\0';
	return (ft_strlen((const char *)src));
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
			break;
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
	processer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!processer)
		return (0);
	i = 0;
	read(fd, buf, BUFFER_SIZE);
	printf("%s\n", buf); // fix this!!
	ft_bzero(processer, BUFFER_SIZE + 1);
	if (ft_is_newline(processer) == 0) // if processer has no new line
	{
		while (read(fd, buf, BUFFER_SIZE) && ft_is_newline(processer) == 0) // as long as there is no new line, read more
		{
			//write(1, "here1\n", 6);
			processer = ft_strjoin(processer, buf); //save to processer. do we need to free buf? typecasting?
			printf("%s\n", processer);
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
	while (i < 1)
	{
		get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

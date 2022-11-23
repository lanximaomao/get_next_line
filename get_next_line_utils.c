/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:39:34 by lsun              #+#    #+#             */
/*   Updated: 2022/11/23 20:29:33 by linlinsun        ###   ########.fr       */
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

size_t	ft_strlen_nl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		return (len + 1);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*joint_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (ft_strdup(s1));
	joint_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
			+ 1);
	if (!joint_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joint_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		joint_str[i++] = s2[j++];
	joint_str[i] = '\0';
	free(s1);
	return (joint_str);
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

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = ft_strlen((char *)src);
	if (!*src && !src)
		return (NULL);
	dest = (char *)ft_calloc((len + 1), sizeof(*src));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	void	*start;

	start = (void *)malloc(size * count);
	if (!start)
		return (0);
	ft_bzero(start, size * count);
	return (start);
}

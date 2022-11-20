/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linlinsun <linlinsun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:39:34 by lsun              #+#    #+#             */
/*   Updated: 2022/11/20 18:57:29 by linlinsun        ###   ########.fr       */
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

size_t	ft_strlen_nl(const char *str) // for a string "abc\ndefg\n\n\n\n123" return 4
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		return(len + 1);
	return (0);
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

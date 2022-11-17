/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:57:40 by lsun              #+#    #+#             */
/*   Updated: 2022/11/17 11:17:46 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
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

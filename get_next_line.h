/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:36:28 by lsun              #+#    #+#             */
/*   Updated: 2022/11/15 16:49:38 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// remove before submissin
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>



char *get_next_line(int fd);

#endif

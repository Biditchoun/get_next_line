/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:10:38 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/13 13:29:43 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_in_buff(char **buff)
{
	char	*temp;
	char	*rt;
	int		i;

	i = str_chr(*buff, '\n') + 1;
	if (!i)
		i = str_len(*buff);
	temp = str_dup(&(*buff)[i]);
	if (!temp)
		return ((char *)rtnull_free(*buff, NULL));
	(*buff)[i] = 0;
	rt = str_dup(*buff);
	if (!rt)
		return ((char *)rtnull_free(temp, *buff));
	free(*buff);
	*buff = temp;
	return (rt);
}

int	read_into_buff(char **buff, int fd)
{
	char	read_result[BUFFER_SIZE + 1];
	char	*temp;
	int		rt;
	int		i;

	rt = read(fd, read_result, BUFFER_SIZE);
	if (rt <= 0)
		return (rt);
	read_result[rt] = 0;
	temp = malloc(str_len(*buff) + str_len(read_result) + 1);
	if (!temp)
		free(*buff);
	if (!temp)
		return (-1);
	i = str_cpy(temp, *buff);
	str_cpy(&temp[i], read_result);
	free(*buff);
	*buff = temp;
	return (rt);
}

char	*get_next_line(int fd)
{
	static char	*buff[FOPEN_MAX] = {NULL};
	int			readrt;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (str_chr(buff[fd], '\n') != -1)
		return (line_in_buff(&buff[fd]));
	readrt = BUFFER_SIZE;
	while (readrt == BUFFER_SIZE && str_chr(buff[fd], '\n') == -1)
		readrt = read_into_buff(&buff[fd], fd);
	if (readrt < 0 || (!readrt && (!buff[fd] || !buff[fd][0])))
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	return (line_in_buff(&buff[fd]));
}

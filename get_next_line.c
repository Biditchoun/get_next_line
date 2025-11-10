/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:52:38 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/10 20:31:49 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_in_buff(char *buff)
{
	char	*temp;
	char	*rt;
	int		i;

	i = str_chr(buff, '\n');
	if (buff[i])
		i++;
	temp = str_dup(&buff[i]);
	if (!temp)
		return ((char *)rtnull_free(buff, NULL));
	buff[i] = 0;
	rt = str_dup(buff);
	if (!rt)
		return ((char *)rtnull_free(temp, buff));
	free(buff);
	buff = temp;
	return (rt);
}

int	read_into_buff(char *buff, int fd)
{
	char	read_result[BUFFER_SIZE + 1];
	char	*temp;
	int		rt;
	int		i;

	rt = read(fd, read_result, BUFFER_SIZE);
	if (rt < 0)
		return (rt);
	read_result[rt] = 0;
	temp = malloc(str_len(buff) + str_len(read_result) + 1);
	if (!temp)
		free(buff);
	if (!temp)
		return (-1);
	i = str_cpy(temp, buff);
	str_cpy(&temp[i], read_result);
	free(buff);
	buff = temp;
	return (rt);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	int			readrt;

	if (str_chr(buff, '\n'))
		return (line_in_buff(buff));
	readrt = BUFFER_SIZE;
	while (readrt == BUFFER_SIZE && !str_chr(buff, '\n'))
		readrt = read_into_buff(buff, fd);
	if (readrt < 0 || (!readrt && !buff[0]))
		return ((char *)rtnull_free(buff, NULL));
	return (line_in_buff(buff));
}

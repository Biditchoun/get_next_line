/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:12:27 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/11 17:13:49 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_len(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	str_cpy(char *dest, const char *src)
{
	int	i;

	if (!src || !dest)
		return (0);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (i);
}

char	*str_dup(const char *s)
{
	char	*rt;
	int		i;

	if (!s)
		return (NULL);
	i = str_len(s);
	rt = malloc(i + 1);
	if (!rt)
		return (NULL);
	str_cpy(rt, s);
	return (rt);
}

int	str_chr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return (i);
	return (-1);
}

void	*rtnull_free(void *p1, void *p2)
{
	free(p1);
	free(p2);
	return (NULL);
}

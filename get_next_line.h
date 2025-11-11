/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:12:08 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/11 14:50:55 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		str_len(const char *s);
int		str_cpy(char *dest, const char *src);
char	*str_dup(const char *s);
int		str_chr(const char *s, int c);
void	*rtnull_free(void *p1, void *p2);
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:12:08 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/11 19:43:24 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 55
# endif

# if BUFFER_SIZE > 2000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 666666
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		str_len(const char *s);
int		str_cpy(char *dest, const char *src);
char	*str_dup(const char *s);
int		str_chr(const char *s, int c);
void	*rtnull_free(void *p1, void *p2);
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:31:17 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/11 19:50:23 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("feur", O_RDONLY);
//	fd = 0;
	char *print = get_next_line(fd);
	int i = 0;
	while (print)
	{
		printf("%02i: %s", i++, print);
		free(print);
		print = get_next_line(fd);
	}
}

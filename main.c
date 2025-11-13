/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:31:17 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/11/13 13:03:39 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("feur", O_RDONLY);
	int fd2 = open("oui", O_RDONLY);
	char *print;
	char *print2;
	char *llun = NULL;
	free(llun);
	int i = 0;
	while (i > -1)
	{
		print = get_next_line(fd);
		print2 = get_next_line(fd2);
		printf("%02i: %s", i, print);
		if (!print)
			printf("\n");
		printf("%02i: %s", i++, print2);
		if (!print && !print2)
			i = -1;
		free(print);
		free(print2);
	}
	close(fd);
	close(fd2);
}

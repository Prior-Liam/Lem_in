/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 20:33:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/04/05 20:46:21 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <fcntl.h>
char    *readandstore(void)
{
	char    *buff;
	char    *final;
	
	final = "\0";
	int fd = open("test.txt", O_RDONLY);
	buff = ft_strnew(BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		final = ft_strjoin(final, buff);
		ft_bzero(buff, BUFF_SIZE);
	}
	free(buff);
	printf("%s%s%s", GREEN, final, NORMAL);
	return (final);
}

int        gnl(t_file *file)
{
	int		size;
	char	*temp;
	
	temp = ft_strnew(BUFF_SIZE);
	file->line = ft_strnew(1);
	while ((file->map[file->offset] == ' ' || file->map[file->offset] == '\n'
			|| file->map[file->offset] == '\t') && file->map[file->offset] != '\0')
		file->offset++;
	while (file->map[file->offset] != '\n' && file->map[file->offset] != '\0')
	{
		size = 0;
		while (size < BUFF_SIZE && file->map[file->offset] != '\n' &&
			   file->map[file->offset] != '\0')

			temp[size++] = file->map[file->offset++];

		file->line = ft_strjoin(file->line, temp);
	}
	if (ft_strcmp(file->line, "\0") == 0)
		return (0);
	return (1);
}

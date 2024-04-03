/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahmani <adahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:12:11 by adahmani          #+#    #+#             */
/*   Updated: 2024/03/13 18:59:00 by adahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*read_file(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*l;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	l = read_file(fd, buffer, backup);
	free(buffer);
	if (!l)
		return (NULL);
	backup = ft_next(l);
	return (l);
}
// #include <fcntl.h>

// int	main(void)
// {
// 	int fd1 = open("non.txt", O_RDONLY);
// 	int fd2 = -3;

// 	char *line;
// 	int i = 0;
// 	while ((line = get_next_line(fd1)))
// 	{
// 		printf("(%d)%s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	line = get_next_line(fd2);
// 	printf("%s", line);
// 	close(fd1);
// 	return (0);
// 	// valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./a.out
// }
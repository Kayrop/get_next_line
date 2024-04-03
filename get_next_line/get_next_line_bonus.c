/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adahmani <adahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:12:11 by adahmani          #+#    #+#             */
/*   Updated: 2024/03/13 19:04:41 by adahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	l = read_file(fd, buffer, backup[fd]);
	free(buffer);
	if (!l)
		return (NULL);
	backup[fd] = ft_next(l);
	return (l);
}
// #include <fcntl.h>
// int    main()
// {
//     int fd1 = open("non.txt", O_RDONLY);
//     int fd2 = open("oui.txt", O_RDONLY);
//     int fd3 = open("autre.txt", O_RDONLY);
//     int fd4 = -3;

//     char *line;
//     char *line2;
//     char *line3;
//     char *line4;
//     int i = 0;

//     while (i < 100)
//     {
// 		line = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
//         printf("(%d)%s", i, line);
// 		printf("(%d)%s", i, line2);
//         free(line);
// 		free(line2);
//         i++;
//     }
//     i = 0;
//     while ((line3 = get_next_line(fd3)))
//     {
//         printf("(%d)%s", i, line3);
//         free(line3);
//         i++;
//     }
//     line4 = get_next_line(fd4);
// 	printf("%s", line4);
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }
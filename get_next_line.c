/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:32:46 by dev               #+#    #+#             */
/*   Updated: 2024/12/12 19:58:33 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	j;

	dstlen = ft_strlen(dst);
	if (dstsize == 0 || dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	i = dstlen;
	j = 0;
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static char	*get_line(char **saved)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (!*saved || !**saved)
		return (NULL);
	if (ft_strchr(*saved, '\n'))
	{
		len = ft_strchr(*saved, '\n') - *saved + 1;
		line = ft_substr(*saved, 0, len);
		if (!line)
			return (free(*saved), *saved = NULL, NULL);
		temp = ft_strdup(*saved + len);
	}
	else
	{
		line = ft_strdup(*saved);
		temp = NULL;
	}
	free(*saved);
	*saved = temp;
	return (line);
}

char	*read_error(char **saved, ssize_t bytes_read, char *buffer)
{
	char	*temp;

	free(buffer);
	if (*saved && **saved && bytes_read == 0)
	{
		temp = ft_strdup(*saved);
		free(*saved);
		*saved = NULL;
		return (temp);
	}
	free(*saved);
	*saved = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved = NULL;
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = malloc((BUFFER_SIZE + 1)
				* sizeof(char))))
		return (NULL);
	while (!saved || !ft_strchr(saved, '\n'))
	{
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) <= 0)
			return (read_error(&saved, bytes_read, buffer));
		buffer[bytes_read] = '\0';
		if (!saved)
			saved = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(saved, buffer);
			free(saved);
			saved = temp;
		}
		if (!saved)
			return (free(buffer), NULL);
	}
	return (free(buffer), get_line(&saved));
}

/* int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */

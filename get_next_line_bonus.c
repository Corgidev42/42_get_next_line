/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:32:46 by dev               #+#    #+#             */
/*   Updated: 2024/12/14 15:26:11 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*saved[1024] = {NULL};
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
		return (read_error(&saved[fd], 0, buffer));
	while (!saved[fd] || !ft_strchr(saved[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (read_error(&saved[fd], bytes_read, buffer));
		buffer[bytes_read] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup("\0");
		temp = ft_strjoin(saved[fd], buffer);
		free(saved[fd]);
		saved[fd] = temp;
	}
	return (free(buffer), get_line(&saved[fd]));
}

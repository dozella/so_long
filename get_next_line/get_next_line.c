/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:26:02 by dozella           #+#    #+#             */
/*   Updated: 2022/01/25 20:04:14 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *rem)
{
	int		i;
	char	*s;

	i = 0;
	if (!rem[i])
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (rem[i] && rem[i] != '\n')
	{
		s[i] = rem[i];
		i++;
	}
	if (rem[i] == '\n')
	{
		s[i] = rem[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_rem(char *rem)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (!rem[i])
	{
		free(rem);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(rem) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (rem[i])
		s[c++] = rem[i++];
	s[c] = '\0';
	free(rem);
	return (s);
}

char	*ft_read(int fd, char *rem)
{
	char	*buf;
	int		bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(rem, '\n') && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		rem = ft_strjoin(rem, buf);
	}
	free(buf);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem = ft_read(fd, rem);
	if (!rem)
		return (NULL);
	line = ft_get_line(rem);
	rem = ft_rem(rem);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:26:57 by dozella           #+#    #+#             */
/*   Updated: 2022/01/25 17:27:00 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int			ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
char		*ft_get_line(char *rem);
char		*ft_rem(char *rem);
char		*ft_read(int fd, char *rem);

#endif

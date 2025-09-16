/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:49:05 by rgregori          #+#    #+#             */
/*   Updated: 2025/07/28 11:11:47 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_node
{
	int					fd;
	char				*stash;
	struct s_fd_node	*next;
}	t_fd_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *s);
char		*get_next_line(int fd);
#endif
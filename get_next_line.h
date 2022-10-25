/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:35:50 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/25 20:44:11 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct l_get
{
	int		indx;
	char	*data;
	char	*line;
	char	*next;
	char	*part;
	int		end;
	int		pass;
}t_get;

char	*get_next_line(int fd);
int		ft_strlen(char *src);
char	*ft_my_strjoin(char *src, char *mot, int a);
char	*ft_my_substr(char *s, int start, int len, int free_or_not);
char	*ft_calloc(int count, int size);
int		ft_strchr(char *str);
void	ft_free_str(char **p);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:24 by yaidriss          #+#    #+#             */
/*   Updated: 2022/10/25 21:16:19 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

void	ft_bzero(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		*(str + i) = 0;
		i++;
	}
}

char	*ft_calloc(int count, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (!result)
		return (0);
	while (i < (count * size))
	{
		*(result + i) = 0;
		i++;
	}
	return (result);
}

void	ft_init_rest(t_get	*line, char **buffer)
{
	line->data = 0;
	*buffer = 0;
	*line->part = 0;
	if (line->data && line->data[0] != 0 && ft_strchr(line->data) == -1)
	{
		*buffer = ft_my_strjoin(line->data, *buffer, 0);
		line->data = 0;
	}
	else if (line->data && line->data[0] != 0)
	{
		*buffer = ft_my_substr(line->data, 0, ft_strchr(line->data) + 1, 0);
		line->data = ft_my_substr(line->data, ft_strchr(line->data) + 1, ft_strlen(line->data), 1);
	}
}

char	*get_next_line(int fd)
{
	t_get		line;
	static char	*buffer = 0;//!need to check
	
	ft_init_rest(&line, &buffer);
	line.data = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line.data)
		return (NULL);
	while(ft_strchr(line.data) != 1 && read(fd, line.data, BUFFER_SIZE) > 0)
	{
		if(ft_strchr(line.data) == -1)
			line.line = ft_my_strjoin(line.line, line.data, 0);
		else
		{
			line.part = ft_my_substr(line.data, 0,ft_strchr(line.data) + 1, 0);
			line.line = ft_my_strjoin(buffer, line.part, 1);
			buffer = ft_my_substr(line.data, ft_strchr(line.data) + 1, ft_strlen(line.data), 1);
		}
		ft_bzero(line.data);
	}
	ft_free_str(&(line.part));
	if ((buffer && *buffer == 0) || (buffer && !line.line))
		ft_free_str(&buffer);
	return(line.line);
}

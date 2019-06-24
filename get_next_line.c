/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 11:28:55 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/24 15:22:52 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_file(int fd, t_list **file)
{
	t_list	*temp;

	if (!file)
		return (NULL);
	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("", fd);
	ft_lstadd(file, temp);
	return (temp);
}

int		ft_line(char *content, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	while (content[i] && content[i] != '\n')
		i++;
	if (!(*line = ft_strndup(content, i)))
		return (0);
	free(temp);
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*current;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0 || !(current = ft_file(fd, &file)))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		temp = current->content;
		current->content = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ret = ft_line(current->content, line);
	temp = current->content;
	if (ret == 0 && temp[0] == '\0')
		return (0);
	if (temp[ret] != '\0')
	{
		current->content = ft_strdup(temp + ret + 1);
		free(temp);
	}
	else
		ft_strclr(current->content);
	return (1);
}

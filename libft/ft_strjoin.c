/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:05:55 by jhansen           #+#    #+#             */
/*   Updated: 2019/06/05 17:08:30 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	string = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (string == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		string[i] = s1[i];
		i++;
	}
	string = ft_strcat(string, s2);
	if (string == NULL)
		return (NULL);
	return (string);
}

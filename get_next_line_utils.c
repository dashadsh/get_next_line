/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:02:05 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/14 15:01:19 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_newline_found(char *s)
{
	size_t		i;

	if (s)
	{
		i = 0;
		while (s[i] && s[i] != '\n')
			i++;
		if (s[i] == '\n')
			return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	newstring = (char *)malloc(sizeof(char) * ft_strlen(s1)
			+ ft_strlen(s2) + 1);
	if (!newstring)
		return (NULL);
	while (s1[i])
	{	
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	free(s1);
	return (newstring);
}

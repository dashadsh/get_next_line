/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:02:05 by dgoremyk          #+#    #+#             */
/*   Updated: 2022/07/08 17:25:27 by dgoremyk         ###   ########.fr       */
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

char	*ft_nl(char *s)   // ft_strchr modified for GNL
{
	size_t		i;

	if (s)  // modified for GNL
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
	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	return (newstring);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)s + i);
// 	return (NULL);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		i;
// 	char		*ptr;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (ft_strlen(s) < len)
// 	{
// 		len = ft_strlen(s);
// 	}
// 	ptr = malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 	{
// 		return (NULL);
// 	}
// 	while (start < ft_strlen(s) && i < len)
// 	{
// 		ptr[i] = s[i + start];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*ptr;
// 	size_t	i;

// 	i = 0;
// 	ptr = (void *)malloc(count * size);
// 	if (!ptr)
// 	{
// 		return (NULL);
// 	}
// 	while (i < count * size)
// 	{
// 		ptr[i] = 0;
// 		i++;
// 	}
// 	return (ptr);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:55:54 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/17 11:46:13 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest == NULL)
		return (NULL);
	while (++i < s1_len)
		dest[i] = s1[i];
	while (j <= s2_len)
		dest[i++] = s2[j++];
	free(s1);
	return (dest);
}

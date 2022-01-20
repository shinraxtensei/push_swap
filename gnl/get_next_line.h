/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 08:56:14 by ahouari           #+#    #+#             */
/*   Updated: 2022/01/17 11:44:52 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen_gnl(char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*change_text(char *result);
char	*ft_strchr_gnl(char *str, int c);
char	*read_line(char *result, int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);

#endif

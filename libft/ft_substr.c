/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:18:25 by thomvan-          #+#    #+#             */
/*   Updated: 2023/11/08 17:55:30 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	l;

	l = ft_strlen(s);
	if (!s)
		return (0);
	i = 0;
	if (len > l)
		len = l;
	if (start + len > l)
		len = l - start;
	if (start > l)
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len && (s[start + i] != '\0'))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

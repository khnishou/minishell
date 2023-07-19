/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:30:46 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 05:10:20 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ms_count_char(char *input, char c)
{
	size_t	nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == c)
			nbr++;
		i++;
	}
	return (nbr);
}

char	*ms_swapstr(char *src, char *swap, size_t start, size_t len)
{
	int		i;
	int		end;
	size_t	src_len;
	char	*res;

	src_len = ft_strlen(src);
	if (!src || start >= src_len)
		return (NULL);
	end = start + len;
	res = malloc(src_len - len + ft_strlen(swap) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < (int) start)
		res[i] = src[i];
	start = 0;
	if (swap)
		while (swap[start])
			res[i++] = swap[start++];
	while (src[end])
		res[i++] = src[end++];
	res[i] = '\0';
	return (res);
}

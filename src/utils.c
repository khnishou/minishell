/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:30:46 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 05:21:41 by ykerdel          ###   ########.fr       */
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

char	*quote_str_get(char *str, size_t tk_count)
{
	size_t	i;
	size_t	j;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(str) - tk_count + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == TK_D_QUOTE || str[i] == TK_S_QUOTE)
			i++;
		else
		{
			res[j] = str[i];
			j++;
			i++;
		}
	}
	res[j] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:30:46 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/18 19:55:59 by ykerdel          ###   ########.fr       */
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

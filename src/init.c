/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:52:38 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/18 20:01:59 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_exe	*ms_init(char *input, int *g_exit_status)
{
	size_t	nbr_pipe;
	t_exe	*exe;
	size_t	i;

	g_exit_status = 0;
	nbr_pipe = ms_count_char(input, TK_PIPE);
	exe = (t_exe *) malloc(sizeof(t_exe) * (nbr_pipe + 1));
	if (!exe)
		ms_exit(MALLOC_ERR);
	i = 0;
	while (i <= nbr_pipe)
	{
		exe[i].index = i;
		i++;
	}
	free(input);
	return (NULL);
}

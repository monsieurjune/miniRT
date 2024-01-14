/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 05:05:20 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/15 05:22:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_error(char *msg1, char *msg2, char *msg3)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg1)
		ft_putendl_fd(msg1, STDERR_FILENO);
	if (msg2)
		ft_putendl_fd(msg2, STDERR_FILENO);
	if (msg3)
		ft_putendl_fd(msg3, STDERR_FILENO);
}

int	parser_open(char *path, int flag)
{
	int		fd;
	char	*err_msg;

	fd = open(path, flag);
	if (fd == -1)
	{
		err_msg = strerror(errno);
		parser_error(err_msg, " : ", path);
	}
	return (fd);
}
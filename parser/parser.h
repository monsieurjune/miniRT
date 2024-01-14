/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:58:17 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/15 06:00:01 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include "../libft/libft.h"

void	parser_error(char *msg1, char *msg2, char *msg3);
int		parser_open(char *path, int flag);

char	**parser_readfile(char *path);
void	parser_free_lines(char ***ptr_unclean);

#endif
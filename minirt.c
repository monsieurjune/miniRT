/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:24:28 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/15 06:10:51 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**lines;

	i = 0;
	(void)argc;
	lines = parser_readfile(argv[1]);
	while (lines[i])
	{
		printf("%s", lines[i]);
		i++;
	}
	parser_free_lines(&lines);
	return (0);
}
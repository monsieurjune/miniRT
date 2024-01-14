/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:58:02 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/15 06:11:08 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static ssize_t	sb_count_nl(char *path)
{
	char		*cmp;
	char		buff;
	ssize_t		nl;
	ssize_t		n;
	int			fd;

	cmp = ft_strchr(ft_strrchr(path, '/'), '.');
	if (ft_strncmp(cmp, ".rt", 5) != 0 || cmp == NULL)
	{
		parser_error("not .rt file => ", cmp, NULL);
		return (-1);
	}
	fd = parser_open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	nl = 0;
	n = read(fd, &buff, 1);
	while (n != 0 && n != -1)
	{
		nl += (buff == '\n');
		n = read(fd, &buff, 1);
	}
	close(fd);
	return (nl * (n != -1) - (n == -1));
}

void	parser_free_lines(char ***ptr_unclean)
{
	ssize_t	i;

	i = 0;
	while ((*ptr_unclean)[i] != NULL)
	{
		free((*ptr_unclean)[i]);
		i++;
	}
	free(*ptr_unclean);
	*ptr_unclean = NULL;
}

static void	sb_gnl_iter(int fd, char ***ptr_unclean, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		(*ptr_unclean)[i] = get_next_line(fd);
		if ((*ptr_unclean)[i] == NULL)
			return (parser_free_lines(ptr_unclean));
		i++;
	}
	(*ptr_unclean)[i] = NULL;
}

char	**parser_readfile(char *path)
{
	int		fd;
	ssize_t	len;
	char	**unclean_box;

	len = sb_count_nl(path);
	if (len <= 0)
		return (NULL);
	unclean_box = malloc(sizeof(char *) * (len + 1));
	if (unclean_box == NULL)
		return (NULL);
	fd = parser_open(path, O_RDONLY);
	if (fd == -1)
	{
		free(unclean_box);
		return (NULL);
	}
	sb_gnl_iter(fd, &unclean_box, len);
	close(fd);
	return (unclean_box);
}
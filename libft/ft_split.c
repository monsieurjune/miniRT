/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 01:05:54 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/04 02:03:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static _Bool	sub_issame(const char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

static char	**sub_failsafe(char **box)
{
	size_t	i;

	i = 0;
	while (box[i])
	{
		free(box[i]);
		i++;
	}
	free(box[i]);
	free(box);
	return (NULL);
}

static char	*sub_strcdup(const char *src, char c)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (src[len] != c && src[len])
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	(void)ft_strlcpy(dest, src, len + 1);
	return (dest);
}

static char	**sub_alloc_box(const char *s, char c, size_t len, size_t i)
{
	char	flag;
	char	**box;
	size_t	j;

	box = ft_calloc(len + 1, sizeof(char *));
	j = 0;
	flag = 1;
	while (s[i] && box)
	{
		if (flag && s[i] != c)
		{
			box[j] = sub_strcdup(&s[i], c);
			if (!box[j])
				return (sub_failsafe(box));
			j += flag--;
		}
		else if (!flag && s[i] == c)
			flag = 1;
		i++;
	}
	return (box);
}

char	**ft_split(char const *s, char c)
{
	char	flag;
	size_t	len;
	size_t	i;

	if (!s || !s[0] || sub_issame(s, c))
		return (ft_calloc(1, sizeof(char *)));
	flag = 1;
	len = 0;
	i = 0;
	while (s[i])
	{
		if (flag && s[i] != c)
			len += flag--;
		else if (!flag && s[i] == c)
			flag = 1;
		i++;
	}
	return (sub_alloc_box(s, c, len, 0));
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	int i = 0;
	(void)ac;
	char **a = ft_split(av[1], av[2][0]);
	while (a[i])
	{
		printf("%d.) %s\n", i, a[i]);
		i++;
	}
	(void)sub_failsafe(a);
	return (0);
}
*/

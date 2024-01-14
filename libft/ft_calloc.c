/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:27:33 by tponutha          #+#    #+#             */
/*   Updated: 2022/08/05 04:45:01 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t byte, size_t size)
{
	void	*mem;

	if (byte == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	byte *= size;
	mem = malloc(byte);
	if (!mem)
		return (NULL);
	return (ft_memset(mem, 0, byte));
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	int *a = ft_calloc(ac, 4);
	for (int i = 0; i < ac; i++)
	{
		a[i] = atoi(av[i]);
	}
	for (int i = 0; i < ac; i++)
	{
		printf("%d.) %d\n", i, a[i]);
	}
	return (0);
}
*/
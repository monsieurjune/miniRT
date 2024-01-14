/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:34:50 by tponutha          #+#    #+#             */
/*   Updated: 2022/09/17 20:55:47 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sub_intlen(int n)
{
	int		len;

	len = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	sub_assign_str(int n, int i, char *str)
{
	if (n >= 10)
		sub_assign_str(n / 10, i - 1, str);
	str[i] = "0123456789"[n % 10];
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == INTMIN)
		return (ft_memcpy(malloc(sizeof(char) * 12), "-2147483648", 12));
	len = sub_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	sub_assign_str(n, len - 1, str);
	str[len] = 0;
	return (str);
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	(void)ac;
	char *a = ft_itoa(atoi(av[1]));
	printf("%s\n", a);
	free(a);
}
*/

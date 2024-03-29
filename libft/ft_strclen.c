/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:08:02 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/15 03:04:28 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *str, int c)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != c && str[len])
		len++;
	return (len);
}

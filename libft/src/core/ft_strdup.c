/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluchini <nluchini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:01:20 by nluchini          #+#    #+#             */
/*   Updated: 2025/09/27 13:47:29 by nluchini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	size = ft_strlen(s1);
	copy = (char *)malloc((size + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, size);
	copy[size] = '\0';
	return (copy);
}

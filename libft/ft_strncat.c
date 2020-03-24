/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:08:50 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/22 16:10:24 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i1;
	size_t		i2;

	i1 = ft_strlen(s1);
	i2 = 0;
	while (s2[i2] && i2 < n)
	{
		s1[i1++] = s2[i2++];
	}
	s1[i1] = '\0';
	return (s1);
}
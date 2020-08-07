/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:22:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 16:23:33 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_format_id(t_all *all)
{
	int		i;

	i = 0;
	while (i < FORMAT_ID_SIZE)
	{
		if (*all->format_ptr == all->format_id_str[i])
		{
			all->format_id = 1 << i;
			all->format_ptr++;
			return (1);
		}
		i++;
	}
	return (0);
}

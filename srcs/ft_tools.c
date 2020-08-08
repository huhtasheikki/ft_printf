/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:05:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 17:02:50 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_variable_len(t_all *all)
{
//	char	*temp;

	if ((all->format_id & DIOUXX_MASK))
	{
//		all->arg_len = ft_strlen(all->convert_str);

/*
		if (all->precision > all->arg_len) // MOVE THIS INSIDE PRECISION FUN?
		{
			if (!(temp = ft_strnew(all->precision + 1)))
				return (-1); //zero? ERROR message etc.
			ft_memset(temp, '0', all->precision - all->arg_len);
			ft_strcat(temp, all->convert_str);
			free(all->convert_str);
			all->convert_str = temp;
			all->arg_len = all->precision;
		}
*/

		all->combined_len = all->arg_len + ft_strlen(all->prefix);
		if (all->combined_len < all->width)
		{
			all->padding_len = all->width - all->combined_len;
			all->combined_len = all->width;
		}
	}
	return (all->combined_len);
}

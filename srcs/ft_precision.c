/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:43:54 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 18:27:57 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_all *all)
{
	char	*temp;

	if (!(all->format_info & (1 << PRECISION_INDEX)))
		return ;
	if ((all->format_id & DIOUXX_MASK))
	{
		if (all->precision == 0 && (all->arg_uint == 0 || all->arg_int == 0))
		{
			free(all->convert_str);
			all->convert_str = ft_strnew(0);
			all->arg_len = 0;
		}
		if (all->precision > all->arg_len)
		{
			if (!(temp = ft_strnew(all->precision + all->prefix_len + 1)))
				return ; //zero? ERROR message etc.
			ft_strcpy(temp, all->prefix);
			all->prefix[0] = '\0';
			ft_memset((temp + all->prefix_len), '0', all->precision - all->arg_len);
			ft_strcat(temp, all->convert_str);
			free(all->convert_str);
			all->convert_str = temp;
			all->arg_len = all->precision + all->prefix_len;
			all->prefix_len = 0;
		}
//		if (all->precision < all->width)
	}
}

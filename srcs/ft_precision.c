/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:43:54 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 16:59:04 by hhuhtane         ###   ########.fr       */
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
		if (all->precision > all->arg_len)
		{
			if (!(temp = ft_strnew(all->precision + 1)))
				return ; //zero? ERROR message etc.
			ft_memset(temp, '0', all->precision - all->arg_len);
			ft_strcat(temp, all->convert_str);
			free(all->convert_str);
			all->convert_str = temp;
			all->arg_len = all->precision;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:05:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 10:55:12 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_variable_len(t_all *all)
{
	if ((all->format_id & DIOUXX_MASK))
	{
		all->arg_len = ft_strlen(all->convert_str);
		all->combined_len = all->arg_len + ft_strlen(all->prefix);
		if (all->combined_len < all->width)
		{
			all->padding_len = all->width - all->combined_len;
			all->combined_len = all->width;
		}
//		all->arg_len = ft_intlen_base(all->arg_int, all->arg_base);
//		all->combined_len;
	}
	return (all->combined_len);
}

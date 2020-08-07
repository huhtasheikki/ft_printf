/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:05:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 16:26:56 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_variable_len(t_all *all)
{
	size_t		len;

	len = 0;
	if ((all->format_id & DIOUXX_MASK))
	{
		all->arg_len = ft_intlen_base(all->arg_int, all->arg_base);
//		all->combined_len;
	}
	return (len);
}

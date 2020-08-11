/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:05:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 15:44:30 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_variable_len(t_all *all)
{
	all->combined_len = all->arg_len + all->prefix_len;
//		all->combined_len = all->arg_len + ft_strlen(all->prefix);
	if (all->combined_len < all->width)
	{
		all->padding_len = all->width - all->combined_len;
		all->combined_len = all->width;
	}
	return (all->combined_len);
}

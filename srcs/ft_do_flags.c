/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:37:32 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 19:22:50 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_flags(t_all *all)
{
	int		i;

	i = 0;
	while (i < FLAGS_SIZE)
	{
		if ((all->format_info & (1 << i)))
		{
			ft_putendl("FLAGS FLAGS FLAGS FLAGS FLAGS FLAGS");
			ft_putnbr(i);
			ft_putendl("FLAGS FLAGS FLAGS FLAGS FLAGS FLAGS");
			all->flags_fun_ptr[i](all);
		}
		i++;
	}
}

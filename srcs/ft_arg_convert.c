/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:42:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/02 13:25:27 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_arg_convert(t_all *all)
{
	int		i;

	i = 0;

	while (i < FORMAT_ID_SIZE)
	{
		ft_putnbr(i);
		if (all->format_id & (1 << i))
		{
			ft_putendl("ENNEN");
			all->convert_fun_ptr[i](all);
			return (1);
		}
//		if (all->format_id_str[i] == all->format_id)
//			all->convert_fun_ptr[i](all);
		i++;
	}
	return (0); // tsek
}

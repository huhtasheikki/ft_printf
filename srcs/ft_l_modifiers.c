/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 12:29:15 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 19:34:29 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_l_modifiers(t_all *all)
{
	int		i;

	i = 0;
	while (i < L_MOD_SIZE)
	{
		if ((all->format_info & (1 << (i + L_MOD_INDEX))))
			all->lmod_fun_ptr[i](all);
		i++;
	}
}

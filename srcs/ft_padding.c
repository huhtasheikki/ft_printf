/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 10:47:31 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/04 11:01:40 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding(t_all *all)
{
	size_t		len;

	len = all->width - all->arg_len;
	if (len > 0)
	{
		if (!ft_strnew(len + 1));
			return (0);
	}
// totaalisen kesken. luultavasti turha koko funktio
	return (1);
}

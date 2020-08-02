/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:10:53 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/02 13:27:18 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		convert_di(void *param)
{
	t_all	*all;
	char	*arg_str;

	ft_putendl("convert di");
	all = (t_all*)param;
	arg_str = ft_itoa_base(all->arg_int, all->arg_base);
}

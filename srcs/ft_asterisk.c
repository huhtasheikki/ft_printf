/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 11:12:45 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 11:17:47 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_get_asterisk(va_list args)
{
	size_t		arg_asterisk;

	arg_asterisk = va_arg(args, int);
	return (arg_asterisk);
}

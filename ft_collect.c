/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:05:41 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/07/02 16:17:51 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_collect_type(t_all *all)
{
	/* ADD LETTERS AS YOU FIND OUT WHICH ONES */
	if (ft_strchr("diouxXDOUc", all->format_char))
		all->arg_i = va_arg(all->ap, intmax_t);
	if (ft_strchr("eEfFgGaA", all->format_char))
		all->arg_d = va_arg(all->ap, double);
//	if (ft_strchr("di", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("ouxX", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("DOU", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("eE", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("fF", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("gG", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
//	if (ft_strchr("aA", all->format_char))
//		all->arg_i = va_arg(all->ap, intmax_t);
}

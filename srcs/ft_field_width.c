/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 10:09:44 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/04 11:15:35 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Probably useless function
static void		ft_arg_len(t_all *all)
{
	if ((all->format_id & DIOUXX_MASK))
		all->arg_len = ft_intlen_base(all->arg_int, all->arg_base);
	//KESKEN MUUT??
}
*/

/*=============*/
/* FIELD WIDTH */
/****************************************************************************/
/* An optional decimal digit string specifying a minimum field width.  If	*/
/* the converted value has fewer characters than the field width, it will	*/
/* be padded with spaces on the left (or right, if the left-adjustment		*/
/* flag has been given) to fill out the field width.						*/
/****************************************************************************/

int				ft_field_width(t_all *all)
{
	size_t		padding_len;

//	ft_arg_len(all);
	padding_len = all->width - all->arg_len;
	if (padding_len > 0)
	{
		free(all->padding_str);
		if (!(all->padding_str = ft_strnew(padding_len + 1)))
			return (0);
		ft_memset(all->padding_str, all->padding_char, padding_len);
	}
	return (1);
}

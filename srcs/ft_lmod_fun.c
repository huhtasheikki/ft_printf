/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmod_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 12:43:51 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 17:44:25 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_h_mod(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
		all->arg_int = (short)all->arg_int;
	else if ((all->format_id & OUXX_MASK))
		all->arg_int = (unsigned short)all->arg_uint;
	else if ((all->format_id & (1 << N_INDEX))) // NOT NEEDED
		all->arg_int = all->arg_int; //
}

void		ft_hh_mod(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
		all->arg_int = (signed char)all->arg_int;
	else if ((all->format_id & OUXX_MASK))
		all->arg_int = (unsigned char)all->arg_uint;
	else if ((all->format_id & (1 << N_INDEX))) // NOT NEEDED
		all->arg_int = all->arg_int; //
}

void		ft_l_mod(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
		all->arg_int = (long)all->arg_int;
	else if ((all->format_id & OUXX_MASK))
		all->arg_int = (unsigned long)all->arg_uint;
	else if ((all->format_id & (1 << N_INDEX))) // NOT NEEDED
		all->arg_int = all->arg_int; //
}

void		ft_ll_mod(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
		all->arg_int = (long long)all->arg_int;
	else if ((all->format_id & OUXX_MASK))
		all->arg_int = (unsigned long long)all->arg_uint;
	else if ((all->format_id & (1 << N_INDEX))) // NOT NEEDED
		all->arg_int = all->arg_int; //
}

void		ft_upl_mod(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	//unknown behaviour;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:16:47 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/11 10:54:03 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags_ptr(t_all *all)
{
	all->flags_fun_ptr[0] = &ft_flag_hash;
	all->flags_fun_ptr[1] = &ft_flag_zero;
	all->flags_fun_ptr[2] = &ft_flag_minus;
	all->flags_fun_ptr[3] = &ft_flag_space;
	all->flags_fun_ptr[4] = &ft_flag_plus;
}

void	ft_init_lmod_ptr(t_all *all)
{
	all->lmod_fun_ptr[0] = &ft_h_mod;
	all->lmod_fun_ptr[1] = &ft_hh_mod;
	all->lmod_fun_ptr[2] = &ft_l_mod;
	all->lmod_fun_ptr[3] = &ft_ll_mod;
	all->lmod_fun_ptr[4] = &ft_upl_mod;
}

void	ft_init_fun_ptr(t_all *all)
{
	all->convert_fun_ptr[0] = &convert_di;
	all->convert_fun_ptr[1] = &convert_di;
	all->convert_fun_ptr[2] = &convert_ouxx;
	all->convert_fun_ptr[3] = &convert_ouxx;
	all->convert_fun_ptr[4] = &convert_ouxx;
	all->convert_fun_ptr[5] = &convert_ouxx;
	all->convert_fun_ptr[E_INDEX] = &convert_double;
	all->convert_fun_ptr[UPE_INDEX] = &convert_double;
	all->convert_fun_ptr[F_INDEX] = &convert_double;
	all->convert_fun_ptr[UPF_INDEX] = &convert_double;
	all->convert_fun_ptr[G_INDEX] = &convert_double;
	all->convert_fun_ptr[UPG_INDEX] = &convert_double;
	all->convert_fun_ptr[S_INDEX] = &convert_str;
	all->convert_fun_ptr[P_INDEX] = &convert_ptr;

	all->convert_fun_ptr[C_INDEX] = &convert_char;
	all->convert_fun_ptr[PERCENT_INDEX] = &convert_percent;
	// MORE FUNTIONS
}

int		ft_initialize(t_all *all, const char *format, size_t *len)
{
	all->format_ptr = (char*)format;
	all->len = len;
	*all->len = 0;
	all->parsed_args = ft_lstnew(NULL, 0);
	all->last_arg = all->parsed_args;
	ft_strncpy(all->flags_str, FLAGS, FLAGS_SIZE + 1);
	ft_strncpy(all->l_modifier_str, L_MODIFIER, L_MOD_SIZE + 1);
	ft_strncpy(all->format_id_str, FORMAT_ID, FORMAT_ID_SIZE + 1);
	ft_init_fun_ptr(all);
	ft_init_flags_ptr(all);
	ft_init_lmod_ptr(all);
	return (1);
}

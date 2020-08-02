/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:16:47 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/02 13:29:53 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
	// MORE FUNTIONS
}

int		ft_initialize(t_all *all, const char *format, size_t *len)
{
	all->format_ptr = (char*)format;
	all->len = len;
	*all->len = 0;
	all->parsed_args = ft_lstnew(NULL, 0);
	ft_reset_format_info(all);
	ft_strncpy(all->flags_str, FLAGS, FLAGS_SIZE + 1);
	ft_strncpy(all->l_modifier_str, L_MODIFIER, L_MOD_SIZE + 1);
	ft_strncpy(all->format_id_str, FORMAT_ID, FORMAT_ID_SIZE + 1);
	ft_init_fun_ptr(all);
	ft_init_flags_ptr(all);
	ft_init_lmod_ptr(all);
	return (1);
}

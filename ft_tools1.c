/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:04:30 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/15 11:23:09 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_combine_strs(char *s1, t_all *all)
{
	size_t		len;
	char		*temp_ptr;

	if (!all->ready_print)
		len = ft_strlen(s1);
	else
		len = ft_strlen(all->ready_print) + ft_strlen(s1);
	temp_ptr = all->ready_print;
	if (!(all->ready_print = ft_memalloc(sizeof(char) * (len + 1))))
		exit (0);
	ft_strcat(all->ready_print, temp_ptr);
	ft_memdel((void**)&temp_ptr);
	ft_strcat(all->ready_print, s1);
}

void	ft_get_nbr(t_all *all)
{
	all->arg_i = va_arg(all->ap, intmax_t);
}

void	ft_get_u_nbr(t_all *all)
{
	intmax_t	nbr;

	nbr = va_arg(all->ap, intmax_t);
	all->arg_ui = (unsigned int)nbr;
}

void	ft_free_parser(t_all *all)
{
	if (all->variable_str)
		ft_memdel((void**)&all->variable_str);
	if (all->variable_begin)
		ft_memdel((void**)&all->variable_begin);
	if (all->variable_end)
		free(all->variable_end);
}

void	ft_del_all(t_all *all)
{
	if (all->ready_print)
		free(all->ready_print);
	if (all->format_ptr)
		free(all->format_ptr);
	if (all)
		free(all);
}

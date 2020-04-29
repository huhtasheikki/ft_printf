/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:14:42 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/28 22:18:43 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_test(void *param)
{
	(void)param;
}

void		ft_reset_variables(t_all *all)
{
	all->variable_str = ft_strnew(0);
	all->variable_begin = ft_strnew(0);
	all->variable_end = ft_strnew(0);
	all->padding_left = ft_strnew(0);
	all->padding_right = ft_strnew(0);
	all->width = 0;
	all->period = 0;
	all->precision = 0;
	all->base = 10;
	all->upper_case = 0;
	all->padding_char = ' ';
	ft_bzero(all->prefix, sizeof(char) * PREFIX);
	ft_bzero(all->flags, sizeof(int) * FLAGS);
	ft_bzero(all->l_modifier, sizeof(int) * L_MODIFIER);
	ft_bzero(all->format_id, sizeof(int) * IDS);
}

void		ft_get_format_id(t_all *all)
{
	int		i;

	i = 0;
	while (i < IDS)
	{
		if (*all->format_ptr == all->format_id_str[i])
		{
			all->format_id[i] = 1;
			all->format_char = *all->format_ptr;
			all->format_ptr++;
			break ;
		}
		i++;
	}
}

void		ft_variable_convert_to_str(t_all *all)
{
	int		i;

	i = 0;
	while (i < IDS)
	{
		if (all->format_id[i] == 1)
			all->format_ft_ptr[i](all);
		i++;
	}
}

int			ft_get_asterisk(t_all *all)
{
	int		asterisk;

	(void)all;
	asterisk = 0;
	return (asterisk);
}

/* make sure you will take care of backlash as well */
void		ft_str_cp_till_percent(t_all *all)
{
	size_t		len;
	char		*text_str;
	char		*percentage_ptr;

	if (!(percentage_ptr = ft_strchr(all->format_ptr, '%')) &&
		!(percentage_ptr = ft_strchr(all->format_ptr, '\\')))
		len = ft_strlen(all->format_ptr);
	else
		len = percentage_ptr - all->format_ptr;
	text_str = ft_strsub(all->format_ptr, 0, len);
	ft_combine_strs(text_str, all);
	ft_memdel((void**)&text_str);
	all->format_ptr = percentage_ptr;
}

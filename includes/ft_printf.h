/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 20:10:08 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/23 18:16:16 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_defs.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"

/*
# define FLAGS 5
# define L_MODIFIER 9
# define IDS 23

typedef struct		s_all
{
	va_list			ap;
	va_list			ap2;
	char			*format_ptr;

	int				flags[FLAGS];
	char			flags_str[FLAGS + 1];
	void			(*flags_ft_ptr[5])(t_all*);

	int				widht;

	int				period;
	int				precision;

	int				l_modifier[L_MODIFIER];
	char			l_modifier_str[L_MODIFIER + 1];

	int				format_id[IDS];
	char			format_id_str[IDS + 1];
	void			(*format_ft_ptr[IDS])(t_all*);

	char			*ready_print;
	char			*variable_str;
}					t_all;
*/

int					ft_printf(const char *format, ...);

void				ft_str_cp_till_percent(t_all *all);
void				ft_combine_strs(char *s1, t_all *all);

int					ft_get_asterisk(t_all *all); /* not done */

void				ft_flags_minus(void *param); /* not done */
void				ft_flags_zero(void *param); /* not done */
void				ft_flags_plus(void *param); /* not done */
void				ft_flags_blank(void *param); /* not done */
void				ft_flags_hash(void *param); /* not done */

void				ft_signed_decimal(void *param); /* not done */
void				ft_unsigned_octal(void *param); /* not done */
void				ft_unsigned_decimal(void *param); /* not done */
void				ft_unsigned_hexa_lo(void *param); /* not done */
void				ft_unsigned_hexa_up(void *param); /* not done */
void				ft_long_int_decimal(void *param); /* not done */
void				ft_long_int_octal(void *param); /* not done */
void				ft_long_int_unsigned_decimal(void *param); /* not done */
void				ft_double_e(void *param); /* not done */
void				ft_double_E(void *param); /* not done */
void				ft_float(void *param); /* not done */
void				ft_double_ef(void *param); /* not done */
void				ft_double_EF(void *param); /* not done */
void				ft_double_a(void *param); /* not done */
void				ft_double_A(void *param); /* not done */
void				ft_unsigned_char_with_l(void *param); /* not done */
void				ft_unsigned_char(void *param); /* not done */
void				ft_unsigned_octal(void *param); /* not done */
void				ft_str(void *param); /* not done */
void				ft_str_with_l(void *param); /* not done */
void				ft_void_ptr(void *param); /* not done */
void				ft_number_char_so_far(void *param); /* not done */
void				ft_percentage(void *param); /* not done */


void				ft_test(void *param); /* USELESS, DELETE WHEN READY */

void				ft_parser(t_all *all);

void				ft_reset_variables(t_all *all);
void				ft_variable_format_id(t_all *all);
void				ft_variable_convert_to_str(t_all *all);

#endif

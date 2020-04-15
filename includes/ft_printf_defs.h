/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_defs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:37:23 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/15 16:00:57 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFS
# define FT_PRINTF_DEFS

#include <stdlib.h>
#include <stdarg.h>

# define FLAGS 5
# define L_MODIFIER 9
# define IDS 24

typedef struct		s_all
{
	va_list			ap;
	va_list			ap2;
	intmax_t		arg_i;
	uintmax_t		arg_ui;
	unsigned int	unsign_arg;
	char			*format_ptr;
	char			padding_char;
	size_t			base;
	int				upper_case;

/* FLAGS = '-' '0' '+' 'BLANK' '#'  */
	int				flags[FLAGS];
	char			flags_str[FLAGS + 1];
	void			(*flags_ft_ptr[5])(void*);

/* MINIMUM FIELD WIDTH */
	int				width;

/* PERIOD AND PRECISION  */
	int				period;
	int				precision;

/* LENGTH MODIFIER aka input modifier (I guess :D) */
	int				l_modifier[L_MODIFIER];
	char			l_modifier_str[L_MODIFIER + 1];

/* FORMAT IDENTIFIER = "diouxXDOUeEfFgGaACcSspn%" */
	int				format_id[IDS];
	char			format_char;
	char			format_id_str[IDS + 1];
	void			(*format_ft_ptr[IDS])(void*);
	
	char			*ready_print;
	char			*variable_str;
	char			*variable_begin;
	char			*variable_end;
	char			*padding_left;
	char			*padding_right;
}					t_all;

#endif
